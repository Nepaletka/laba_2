#pragma once

int experiment(double *radioactivity, double *time, double start_time, double end_time, double step, double beta);
void add_noise(double *radioactivity, int N);
double nonlinear_equation(double *radioactivity, double *time, int N, double precision, double interval1, double interval2);
double model(double decay_time, double *radioactivity, double *time, int N);
double linear_equation(double *radioactivity, double *time, int N);
double precision_analysis(double *radioactivity, double *time, int N, double precision, double  interval1, double interval2);
double dev_exp(double *radioactivity, double *time, int M, double decay_time);
double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);
