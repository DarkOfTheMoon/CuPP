/**
 * @file 
 *
 * Common definitions and helper macros of the Cupp project.
 *
 * Copyright: See COPYING file that comes with this distribution
 */

#ifndef CUPP_cupp_common_H
#define CUPP_cupp_common_H



#if defined(__CUDACC__)
	#define CUPP_RUN_ON_HOST __host__
	#define CUPP_RUN_ON_DEVICE __device__
	#define CUPP_GLOBAL __global__
	#define CUPP_CONSTANT __constant__
	#define CUPP_SHARED __shared__
#else
	/**
	 * @def CUPP_RUN_ON_HOST
	 * Specifies a function as accessible from the host.
	 */
	#define CUPP_RUN_ON_HOST
	
	/**
	 * @def CUPP_RUN_ON_DEVICE
	 * Specifies a function as accessible from the device.
	 */
	#define CUPP_RUN_ON_DEVICE
	
	#define CUPP_GLOBAL
	#define CUPP_CONSTANT
	#define CUPP_SHARED
#endif

/**
 * Macro to surpress warning that a function parameter isn't used.
 */
#define UNUSED_PARAMETER(expr) (void)sizeof(expr)

#endif // CUPP_cupp_common_H
