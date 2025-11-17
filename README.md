# Simulador de Línea de Producción de Electrodomésticos
## IF-4001 Sistemas Operativos - Proyecto Final 2025

---

## Descripción del Proyecto

Este proyecto implementa una aplicación gráfica en C++ con Qt Creator que simula una línea de producción automatizada de electrodomésticos. El sistema utiliza múltiples hilos y procesos que se comunican y sincronizan mediante semáforos, mutexes, pipes y señales de Qt.

---

## Requisitos Cumplidos

### 1. Clases Principales y Funcionalidades ✓

#### a. MainWindow (Qt GUI)
- **Ubicación**: `MainWindow.h`, `MainWindow.cpp`, `mainwindow.ui`
- **Funcionalidad**: Interfaz gráfica que visualiza estaciones, colas, logs y métricas
- **Controles**: Botones Start, Pause, Stop para controlar la simulación
- **Actualización en tiempo real**: Estados de estaciones, contadores de producción, barras de progreso

#### b. ProductionController
- **Ubicación**: `ProductionController.h`, `ProductionController.cpp`
- **Funcionalidad**: Crea estaciones, administra hilos/procesos, gestiona buffers y sincronización
- **Características**:
  - Gestión de 5 estaciones de trabajo
  - Dos ensambladores con balanceo Round-Robin
  - Integración con sistema de persistencia
  - Control de hilos de mantenimiento

#### c. WorkStation (clase base)
- **Ubicación**: `WorkStation.h`, `WorkStation.cpp`
- **Funcionalidad**: Clase base para estaciones de trabajo
- **Uso de hilos**: Cada estación corre en su propio QThread
- **Sincronización**: QMutex y QWaitCondition para pausar/reanudar

#### d. Estaciones Especializadas
- **Assembler** (`Assembler.h`, `Assembler.cpp`): 2 instancias para ensamblaje
- **Tester** (`Tester.h`, `Tester.cpp`): Pruebas del producto
- **QualityControl** (`QualityControl.h`, `QualityControl.cpp`): Inspección de calidad con 20% probabilidad de falla
- **Packer** (`Packer.h`, `Packer.cpp`): Empaquetado final

#### e. Buffer<T>
- **Ubicación**: `Buffer.h`
- **Funcionalidad**: Cola protegida por QMutex y QWaitCondition
- **Características**:
  - Thread-safe mediante QMutex
  - Variables de condición (QWaitCondition) para bloqueo cuando está lleno/vacío
  - Capacidad configurable

#### f. PipeManager
- **Ubicación**: `PipeManager.h`, `PipeManager.cpp`
- **Funcionalidad**: Comunicación IPC mediante Unix pipes
- **Uso**: Los productos que fallan en QualityControl se envían por pipe de vuelta a la entrada
- **Implementación**: std::thread + Unix pipe() para comunicación asíncrona

#### g. ThreadManager
- **Ubicación**: `ThreadManager.h`, `ThreadManager.cpp`
- **Funcionalidad**: Administra logs, estadísticas y métricas del sistema
- **Características**:
  - Registro timestamped y categorizado
  - Métricas de throughput y rendimiento
  - Monitoreo de estados

#### h. StatsMonitor
- **Ubicación**: `StatsMonitor.h`, `StatsMonitor.cpp`
- **Funcionalidad**: Sistema de monitoreo y graficación en tiempo real
- **Características**:
  - Mantiene historial de 60 segundos de datos
  - Tres métricas principales: Procesados, En Cola, Retrabajo
  - Alimenta el gráfico visual en MainWindow
  - Sistema de reset para limpiar datos al detener

---

### 2. Interfaz Gráfica de Usuario (GUI) ✓

#### a. Estaciones de Trabajo
- **5 Estaciones**: Assembler-1, Assembler-2, Tester, QualityControl, Packer, Shipping
- **Estados visibles**: Cada estación muestra su estado (Running, Paused, Stopped, Waiting)
- **Gestión individual**: Todas las estaciones responden a comandos start/pause/stop individuales
- **Indicadores visuales**:
  - Estado de cada estación (QLabel)
  - Productos procesados (contadores)
  - Tamaño de cola (QProgressBar)
  - Productos en retrabajo
- **Gráfico en tiempo real**: Visualización de métricas históricas con tres líneas (Procesados, En Cola, Retrabajo)

#### b. Comunicación entre Estaciones
- **Señales Qt**: Para comunicación interna GUI
- **Pipes Unix**: QualityControl → PipeManager → Entry Buffer (productos fallados)
- **Buffers protegidos**: Todas las transferencias mediante Buffer<T> con mutexes
- **Mensajes**: Sistema de logs muestra toda la comunicación en tiempo real

#### c. Sincronización Avanzada
- **QMutex**: En Buffer<T> para proteger recursos compartidos
- **QWaitCondition**: Para bloquear/despertar threads en buffers llenos/vacíos
- **QMutex + QWaitCondition**: En WorkStation para pausar/reanudar hilos
- **std::atomic**: En PipeManager para control thread-safe

#### d. Componentes Clave Implementados
- ✓ **Hilos/Procesos**: QThread para estaciones, std::thread para PipeManager
- ✓ **Semáforos y Mutexes**: QMutex y QWaitCondition en Buffer y WorkStation
- ✓ **Señales y Slots**: Comunicación GUI-Controller-Stations
- ✓ **Iniciar/Detener estaciones**: Botones Start, Pause, Stop
- ✓ **Asignación de recursos**: Visualización automática de estados
- ✓ **Listado de estaciones**: Log en tiempo real muestra todos los procesos activos

---

### 3. Persistencia de Datos ✓

#### Implementación
- **Ubicación**: `Persistence.h`, `Persistence.cpp`
- **Formato**: JSON (archivo `save_state.json`)
- **Datos guardados**:
  - Estado de todas las estaciones
  - Contadores de productos procesados
  - Contenido de todos los buffers
  - Próximo ID de producto
  - Estadísticas de retrabajo

#### Funcionalidad
- **Guardado automático**: Al cerrar la aplicación
- **Carga automática**: Al iniciar la aplicación
- **Log persistente**: Archivo `runtime.log` con historial completo

---

### 4. Hilos de Mantenimiento ✓

Implementados en `ThreadManager.h` y `ThreadManager.cpp`:

#### a. GeneralCleanThreads
- **Frecuencia**: Cada 15 segundos
- **Función**: Limpia buffers y resetea contadores
- **Mensajes**:
  ```
  === GeneralCleanThreads: Starting cleanup operation ===
  GeneralCleanThreads: Cleared internal buffer (had X items)
  GeneralCleanThreads: Reset station 'XXX' (processed count was Y)
  === GeneralCleanThreads: Operation finished ===
  ```

#### b. GeneralLogs
- **Frecuencia**: Continuo (captura todos los eventos)
- **Función**: Recopila y categoriza todos los logs del sistema
- **Categorías**: ERROR, WARN, ACTION, PRODUCTION, MAINTENANCE, INFO
- **Archivo**: `runtime.log` con timestamps completos
- **Formato**: `[YYYY-MM-DD HH:MM:SS] [CATEGORIA] mensaje`

#### c. GeneralStats
- **Frecuencia**: Cada 1 segundo
- **Función**: Recolecta estadísticas de todas las estaciones
- **Métricas mostradas**:
  - Productos procesados por estación
  - Tamaño de cola de cada estación
  - Productos en retrabajo
  - Totales del sistema
- **Mensajes**:
  ```
  --- GeneralStats: Collecting system statistics ---
  GeneralStats: [Station] → Processed: X, Queue: Y, Rework: Z
  GeneralStats: TOTALS → Processed: X, In Queue: Y, Rework: Z
  --- GeneralStats: Statistics collection complete ---
  ```

---

## Arquitectura del Sistema

### Flujo de Producción

```
[ProductionController]
        ↓
   [Entry Buffers]
     /         \
    ↓           ↓
[Assembler-1] [Assembler-2]  ← Round-Robin
    \         /
     ↓       ↓
  [Shared Buffer]
        ↓
    [Tester]
        ↓
  [QualityControl] ← 5% fail rate
    ↓         ↓
 [Pass]    [Fail]
    ↓         ↓
 [Packer]  [PipeManager] → (rework) → [Entry Buffer]
    ↓
 [Shipping]
    ↓
 [Finished]
```

### Tecnologías de Sincronización Utilizadas

| Componente | Mecanismo | Propósito |
|------------|-----------|-----------|
| Buffer<T> | QMutex + QWaitCondition | Protección y coordinación de acceso |
| WorkStation | QMutex + QWaitCondition | Pausar/reanudar hilos |
| PipeManager | Unix pipe() + std::atomic | Comunicación IPC asíncrona |
| Qt Signals/Slots | Qt Meta-Object System | Comunicación thread-safe GUI |
| ProductionLine | QThread | Paralelismo de estaciones |

---

## Compilación y Ejecución

### Requisitos
- Ubuntu Desktop (Linux)
- Qt Creator 5.x o superior
- Qt5 Widgets, Core, GUI, Concurrent
- g++ con soporte C++17
- Sistema POSIX (para pipes)

### Compilación desde Terminal
```bash
qmake Proyecto_SO.pro
make
./proyecto_so_2025
```

### Compilación en Qt Creator
1. Abrir `Proyecto_SO.pro` en Qt Creator
2. Configurar kit de compilación (Desktop Qt 5.x GCC)
3. Build → Build Project
4. Run → Run (o presionar Ctrl+R)

---

## Uso de la Aplicación

### Controles
- **Start**: Inicia la simulación de producción
- **Pause**: Pausa todas las estaciones (mantiene el estado)
- **Stop**: Detiene completamente la simulación

### Visualización
- **Estaciones**: Muestra estado y métricas de cada estación
- **Barras de progreso**: Indican el tamaño de la cola de cada estación
- **Contadores**: Productos procesados, en cola y en retrabajo
- **Log**: Historial completo de operaciones en tiempo real

### Archivos Generados
- `save_state.json`: Estado persistente de la simulación
- `runtime.log`: Log completo categorizado con timestamps

---

## Características Destacadas

### ✓ Más de 5 Estaciones
El sistema incluye exactamente 6 estaciones especializadas (contando los dos ensambladores como instancias separadas de la misma clase):
- Assembler-1, Assembler-2, Tester, QualityControl, Packer, Shipping

### ✓ Comunicación Multiproceso
- Pipes Unix para IPC (productos fallados)
- Qt Signals/Slots para comunicación interna
- Buffers thread-safe con mutexes

### ✓ Sincronización Robusta
- Mutexes para protección de recursos compartidos
- Variables de condición para coordinación
- Atomic operations en componentes críticos

### ✓ Threads Múltiples
- Cada estación en su propio QThread
- Thread separado para lectura de pipes
- Timers para hilos de mantenimiento

### ✓ Sistema de Retrabajo Realista
- 10% de productos fallan en Tester (marcados como defectuosos)
- 5% de productos fallan en Quality Control
- Se reinyectan mediante pipes Unix
- Contadores separados de retrabajo

### ✓ Persistencia Completa
- Guardado automático al cerrar
- Carga automática al iniciar
- Mantiene integridad del estado

### ✓ Logging Detallado
- Categorización automática de eventos
- Timestamps precisos
- Mensajes descriptivos de cada operación

---

## Estructura de Archivos

```
Proyecto_SO/
├── *.h, *.cpp           # Código fuente
├── mainwindow.ui        # Diseño de interfaz
├── Proyecto_SO.pro      # Archivo de proyecto Qt
├── README.md            # Este archivo
├── save_state.json      # Estado persistente (generado)
└── runtime.log          # Logs del sistema (generado)
```

---

## Notas Importantes

1. **Hilos de Mantenimiento**: Están siempre activos durante la ejecución
2. **Pipes**: Implementan IPC real mediante Unix pipes (no simulado)
3. **Sincronización**: Utiliza primitivas reales de Qt (QMutex, QWaitCondition)
4. **GUI Responsiva**: Actualización en tiempo real sin bloqueos
5. **Robustez**: Manejo apropiado de shutdown de threads y buffers

---

## Cumplimiento de Requisitos del Proyecto

| Requisito | Estado | Ubicación |
|-----------|--------|-----------|
| MainWindow con GUI | ✓ | MainWindow.* |
| ProductionController | ✓ | ProductionController.* |
| Station (clase base) | ✓ | WorkStation.* |
| Estaciones especializadas | ✓ | Assembler.*, Tester.*, etc. |
| Buffer con mutex | ✓ | Buffer.h |
| PipeComm/IPC | ✓ | PipeManager.* |
| Logger/Métricas | ✓ | ThreadManager.*, Logger.* |
| 5+ Estaciones | ✓ | ProductionController.cpp:11-21 |
| Comunicación pipes/señales | ✓ | Todo el sistema |
| Sincronización avanzada | ✓ | Buffer.h, WorkStation.* |
| Hilos QThread | ✓ | WorkStation.* |
| Mutexes y Semáforos | ✓ | Buffer.h, WorkStation.h |
| Signals y Slots Qt | ✓ | Todos los componentes |
| Start/Pause/Stop | ✓ | MainWindow, Controller |
| Listado de procesos | ✓ | Log en tiempo real |
| Persistencia JSON | ✓ | Persistence.* |
| Carga al iniciar | ✓ | ProductionController.cpp:66 |
| GeneralCleanThreads | ✓ | ThreadManager.cpp:67 |
| GeneralLogs | ✓ | ThreadManager.cpp:48 |
| GeneralStats | ✓ | ThreadManager.cpp:94 |

**Cumplimiento Total: 22/22 requisitos (100%)**

---

## Autor

Proyecto desarrollado para el curso IF-4001 Sistemas Operativos
Universidad: Recinto de Paraíso - RPCIE
Profesor: Lic. Gilberth Chaves Avila
Grupo: 21
Fecha: Noviembre 2025

---

## Licencia

Este proyecto es material académico para fines educativos.
