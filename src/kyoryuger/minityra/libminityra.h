#ifndef LIBMINITYRA_H
#define LIBMINITYRA_H

#define MODE_OVERCHARGE 0x1
#define MODE_CARNIVAL   0x2

#ifdef __cplusplus
extern "C"{
#endif
  extern int SetupGPIO(void);
  extern int SetJudenchi(int id);
  extern int Gabu(void);
  extern int Kururincho(int mode);
  extern int DockGaburevolver(void);
  extern int UndockGaburevolver(void);
  extern int Trigger(void);
  extern int SideSwitch(void);
#ifdef __cplusplus
}
#endif


#endif /* LIBMINITYRA_H */
