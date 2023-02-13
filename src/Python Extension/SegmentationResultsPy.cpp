#include "SegmentationResultsPy.h"

namespace PythonAlgorithms
{
	SegmentationResults::SegmentationResults()
	{
		_numberOfBinaryEvents		= 0;
		_jumpSequenceVariance		= 0;
		_segmentDensity				= 0;
		_iterations					= 0;
		_error						= 0;

		_binaryEventSequence		= py::array_t<double>();
		_filteredSignal				= py::array_t<double>();
		_segmentedLog				= py::array_t<double>();
		_noiseVariance				= py::array_t<double>();
	}

	SegmentationResults::SegmentationResults(Algorithms::SegmentationResults* segmentationResults)
	{
		// Initial scalar values from the input.
		_signalLength				= segmentationResults->GetSignalLength();
		_numberOfBinaryEvents		= segmentationResults->GetNumberOfBinaryEvents();
		_jumpSequenceVariance		= segmentationResults->GetJumpSequenceVariance();
		_segmentDensity				= segmentationResults->GetSegmentDensity();
		_iterations					= segmentationResults->GetIterations();
		_error						= segmentationResults->GetError();

		// Create the arrays.
		_binaryEventSequence		= py::array_t<double>(_signalLength);
		_filteredSignal				= py::array_t<double>(_signalLength);
		_segmentedLog				= py::array_t<double>(_signalLength);
		_noiseVariance				= py::array_t<double>(_signalLength);

		// Get pointers to the results.  The data is private, we use the access functions.
		double* binaryEventSequence = segmentationResults->GetBinaryEventSequence();
		double* filteredSignal		= segmentationResults->GetFilteredSignal();
		double* segmentedLog		= segmentationResults->GetSegmentedLog();
		double* noiseVariance		= segmentationResults->GetNoiseVariance();

		// Get pointers to the actual data inside of the Python arrays.
		double* binaryEventSequenceBuffer	= static_cast<double*>(_binaryEventSequence.request().ptr);
		double* filteredSignalBuffer		= static_cast<double*>(_filteredSignal.request().ptr);
		double* segmentedLogBuffer			= static_cast<double*>(_segmentedLog.request().ptr);
		double* noiseVarianceBuffer			= static_cast<double*>(_noiseVariance.request().ptr);

		// Copy the data to the Python data structures.
		for (int i = 0; i < _signalLength; i++)
		{
			binaryEventSequenceBuffer[i]	= binaryEventSequence[i];
			filteredSignalBuffer[i]			= filteredSignal[i];
			segmentedLogBuffer[i]			= segmentedLog[i];
			noiseVarianceBuffer[i]			= noiseVariance[i];
		}
	}

	SegmentationResults::~SegmentationResults()
	{
	}

	py::array_t<double> SegmentationResults::GetBinaryEventSequence()
	{
		return _binaryEventSequence;
	}

	int SegmentationResults::GetNumberOfBinaryEvents()
	{
		return _numberOfBinaryEvents;
	}

	py::array_t<double> SegmentationResults::GetFilteredSignal()
	{
		return _filteredSignal;
	}

	py::array_t<double> SegmentationResults::GetSegmentedLog()
	{
		return _segmentedLog;
	}

	py::array_t<double> SegmentationResults::GetNoiseVariance()
	{
		return _noiseVariance;
	}

	double SegmentationResults::GetJumpSequenceVariance()
	{
		return _jumpSequenceVariance;
	}

	double SegmentationResults::GetSegmentDensity()
	{
		return _segmentDensity;
	}
		
	int SegmentationResults::GetIterations()
	{
		return _iterations;
	}

	int SegmentationResults::GetError()
	{
		return _error;
	}

} // End namespace.