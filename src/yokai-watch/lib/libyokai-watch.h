#ifndef LIBYOKAI_WATCH_H
#define LIBYOKAI_WATCH_H


#ifdef __cplusplus
extern "C"{
#endif
  extern int SetupGPIO(void);
  extern int EjectMedal(void);
  extern int SetMedal(int pattern);
#ifdef __cplusplus
}
#endif


#endif /* LIBYOKAI_WATCH_H */
