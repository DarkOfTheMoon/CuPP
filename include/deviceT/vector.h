/*
 * Copyright: See COPYING file that comes with this distribution
 *
 */

#ifndef CUPP_DEVICET_vector_H
#define CUPP_DEVICET_vector_H

#include "cupp_common.h"
#include "deviceT/memory1d.h"

namespace cupp {

template <typename T>
class vector;

namespace deviceT {

/**
 * @class vector
 * @author Jens Breitbart
 * @version 0.1
 * @date 24.07.2007
 * @platform Device only
 */

template< typename T >
class vector : public memory1d<T, cupp::vector<T> > {
	public:
		/**
		 * @typedef size_type
		 * @brief The type you should use to index this class
		 */
		typedef typename memory1d<T, cupp::vector<T> >::size_type size_type;

		/**
		 * @typedef value_type
		 * @brief The type of data you want to store
		 */
		typedef typename memory1d<T, cupp::vector<T> >::value_type value_type;

		/**
		 * Creates an empty and useless vector :-)
		 */
		vector () {}
		
		/**
		 * Constructor
		 * @param size The size of the memory to be pointed to
		 * @param device_pointer The pointer to the memory (device pointer!)
		 */
		vector ( size_type size, T* device_pointer) : memory1d<T, cupp::vector<T> >(size, device_pointer) {}
};

} // namespace deviceT
} // namespace cupp

#endif