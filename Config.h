#ifndef CONFIG_H
#define CONFIG_H
#include <QRandomGenerator>
class Config {
public://CONSTANTES DE VELOCIDAD
    static inline int assemblerDelay = 500;
    static inline int testerDelay = 700;
    static inline int qcDelay = 600;
    static inline int packerDelay = 500;
    static inline int shipDelay      = 400;
    static inline int failProb = 40;

};

#endif // CONFIG_H
