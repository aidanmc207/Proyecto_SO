QT += core gui widgets concurrent
CONFIG += c++17
TEMPLATE = app
TARGET = proyecto_so_2025

SOURCES += \
    QualityControl.cpp \
    main.cpp \
    MainWindow.cpp \
    ProductionController.cpp \
    ProductionLine.cpp \
    WorkStation.cpp \
    Assembler.cpp \
    Tester.cpp \
    Packer.cpp \
    Logger.cpp \
    StatsMonitor.cpp \
    CleanUpService.cpp \
    Persistence.cpp \
    ThreadManager.cpp \
    PipeManager.cpp \
    product.cpp

HEADERS += \
    MainWindow.h \
    ProductionController.h \
    ProductionLine.h \
    QualityControl.h \
    WorkStation.h \
    Assembler.h \
    Tester.h \
    Packer.h \
    Buffer.h \
    Logger.h \
    StatsMonitor.h \
    CleanUpService.h \
    Persistence.h \
    ThreadManager.h \
    PipeManager.h \
    product.h

FORMS += \
    mainwindow.ui
