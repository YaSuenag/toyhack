#ifndef LIBGABUREVOLVER_H
#define LIBGABUREVOLVER_H


#ifdef __cplusplus
extern "C"{
#endif
  extern int SetupGPIO(void);
  extern int OpenSetter(void);
  extern int SetJudenchi(int lower_sw, int upper_sw);
  extern int CloseSetter(void);
  extern int Rotate(void);
  extern int Trigger(void);
  extern int DockMinityra(void);
  extern int UndockMinityra(void);
  extern int DockGaburicalibur(void);
  extern int UndockGaburicalibur(void);
#ifdef __cplusplus
}
#endif


#endif /* LIBGABUREVOLVER_H */
