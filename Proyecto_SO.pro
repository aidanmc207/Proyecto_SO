QT += core gui widgets concurrent
CONFIG += c++17
TEMPLATE = app
TARGET = proyecto_so_2025

SOURCES += \
    LogWindow.cpp \
    QualityControl.cpp \
    StatsWindow.cpp \
    firstView.cpp \
    main.cpp \
    MainWindow.cpp \
    ProductionController.cpp \
    ProductionLine.cpp \
    WorkStation.cpp \
    Assembler.cpp \
    Tester.cpp \
    Packer.cpp \
    Shipping.cpp \
    Logger.cpp \
    StatsMonitor.cpp \
    CleanUpService.cpp \
    Persistence.cpp \
    ThreadManager.cpp \
    PipeManager.cpp \
    product.cpp

HEADERS += \
    Config.h \
    LogWindow.h \
    MainWindow.h \
    ProductionController.h \
    ProductionLine.h \
    QualityControl.h \
    StatsWindow.h \
    WorkStation.h \
    Assembler.h \
    Tester.h \
    Packer.h \
    Shipping.h \
    Buffer.h \
    Logger.h \
    StatsMonitor.h \
    CleanUpService.h \
    Persistence.h \
    ThreadManager.h \
    PipeManager.h \
    firstView.h \
    product.h

FORMS += \
    LogWindow.ui \
    StatsWindow.ui \
    firstView.ui \
    mainwindow.ui
