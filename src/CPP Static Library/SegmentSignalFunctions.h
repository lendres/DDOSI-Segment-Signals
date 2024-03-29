#ifndef SEGMENTSIGNALFUNCTIONS_H
#define SEGMENTSIGNALFUNCTIONS_H
/*
	C function calls for the signal segmentation libary.
	These functions are where the work is performed.
*/

// MAIN FUNCTION
//                 In                                                                               Out
void SegmentSignal(double LOG[], int NSAMPS, double F, int ORDER, int ORDER1, int RMODE, int NITER, int Q[], int& NQ, double FLTLOG[], double SEGLOG[], double R[], double& C, double& D, int& NACT, int& IER);

// HELPER FUNCTIONS
//                                   In                                                               Out
void SingleMostLikelihoodReplacement(double G[], double S[], double C, int NSAMPS, double D, int Q[], bool& CONV, int& IER);

//             In                                               Out
void Threshold(double JMPSEQ[], double C, double F, int NSAMPS, int Q[], double& D);

//                 In                                    Out
void MovingAverage(double ARR1[], int NSAMPS, int ORDER, double ARR2[]);

//                In                                                       Out
void KalmanFilter(double LOG[], int Q[], double C, double R[], int NSAMPS, double GAIN[], double ZTLT[], double ETA[], double STATE[]);

//                                In                             In/Out
void FixedIntervalOptimalSmoother(int Q[], int NSAMPS, double C, double ARR1[], double ARR2[], double ARR3[]);

//                        In                                 Out
void AverageArraySegments(double ARR[], int Q[], int NSAMPS, double AVGOUT[]);

//                                    In                                            Intermediate    Out
void DeglitchAndEstimateNoiseVariance(double LOG[], int Q[], int NSAMPS, int RMODE, double WORK1[], double R[]);

//              In                                             Out
void GetSegment(double LOG[], int Q[], int NSAMPS, int SEGSTR, int& SEGEND, int& SEGLEN, double& SEGAVG, bool& endofarray);

//            In          In/Out
void Deglitch(int NSAMPS, int Q[]);

//                 In                               Out
void GetSpikeyZone(int Q[], int NSAMPS, int SEGSTR, int& SEGEND, bool& endofarray);

//                        In                   Out
void EstimateEventDensity(int Q[], int NSAMPS, double& D, int& NQ);

//                                  In                        Intermediate    Out
void EstimateVarianceOfJumpSequence(double LOG[], int NSAMPS, double WORK1[], double& C);

//                            In                                    Out
void CalculateMeanAndVariance(double ARRAY[], int NSAMPS, int MODE, double& MEAN, double& VAR);

#endif