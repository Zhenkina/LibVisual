/* fft.h: Header for iterative implementation of a FFT
 * Copyright (C) 1999 Richard Boulton <richard@tartarus.org>
 */

#ifndef _LV_FFT_H
#define _LV_FFT_H

#include "lv_common.h"

/**
 * Private FFT define that contains the log size.
 */
#define VISUAL_FFT_BUFFER_SIZE_LOG 9
/**
 * Private FFT define that contains the buffer size.
 */
#define VISUAL_FFT_BUFFER_SIZE (1 << VISUAL_FFT_BUFFER_SIZE_LOG)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _VisFFTState VisFFTState;

/**
 * Private structure to contain Fast Fourier Transform states in.
 */
struct _VisFFTState {
	/* Temporary data stores to perform FFT in. */
	float real[VISUAL_FFT_BUFFER_SIZE];	/**< Private data that is used by the FFT engine. */
	float imag[VISUAL_FFT_BUFFER_SIZE];	/**< Private data that is used by the FFT engine. */
};

VisFFTState *_lv_fft_init (void);
void _lv_fft_perform (const int16_t *input, float *output, VisFFTState *state);
void _lv_fft_close (VisFFTState *state);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LV_FFT_H */
