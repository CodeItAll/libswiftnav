/*
 * Copyright (C) 2014 Swift Navigation Inc.
 * Contact: Ian Horn <ian@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBSWIFTNAV_AMBIGUITY_TEST_H
#define LIBSWIFTNAV_AMBIGUITY_TEST_H
#include "constants.h"
#include "common.h"

typedef struct {
  u32 res_dim;
  u8 null_space_dim;
  double null_projector[(MAX_CHANNELS-4) * (MAX_CHANNELS-1)];
  double res_cov_inverse[(2*MAX_CHANNELS - 5) * (2*MAX_CHANNELS - 5)];
} residual_mtxs_t;

void init_residual_matrices(residual_mtxs_t *res_mtxs, u8 num_dds, double *DE_mtx, double *obs_covar);
void assign_phase_obs_null_basis(u8 num_sats, double *DE_mtx, double *q);
void assign_r_vec(residual_mtxs_t *res_mtxs, u8 num_dds, double *dd_measurements, double *r_vec);
void assign_r_mean(residual_mtxs_t *res_mtxs, u8 num_dds, s8 *hypothesis, double *r_mean);
double assign_quadratic_term(residual_mtxs_t *res_mtxs, u8 num_dds, s8 *hypothesis, double *r_vec);

#endif /* LIBSWIFTNAV_AMBIGUITY_TEST_H */