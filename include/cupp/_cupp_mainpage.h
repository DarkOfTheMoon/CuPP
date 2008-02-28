/**
 * \mainpage
 * 
 * \section intro Introduction
 * The CuPP framework has been developed to ease the integration of CUDA into C++
 * applications. It enhances CUDA by offering automatic device/host memory management, data structures
 * and a special kernel call semantic, similar to call by reference as it is known from the C++ realm.
 * 
 * \section HP Homepage
 * - CuPP homepage: http://cupp.gpuified.de/
 * - Google group: ???
 * 
 * \section rel_notes Release Notes
 * <a href="static/cupp_v1_prev.tar.gz">Download CuPP</a>
 * 
 * This is the first preview release of CuPP. It is only testes on Ubuntu Linux (32bit),
 * but it is expected to work well on other linux flavors. Windows is untested and not expected to work
 * correctly, but may be in an upcoming release.
 * 
 * The downloadable file contains:
 * - the CuPP framework itself
 * - simple example applications, that demonstrate the usage of CuPP
 * - parts of the Boost Libraries used by CuPP (including a slidely modified version of
 *   <a href="http://www.boost.org/doc/html/boost_typetraits.html">Boost.TypeTraits</a>,
 *   which supports a higher function arity in function_traits.
 * 
 * \section start Getting Started
 * \subsection req Requirements
 * The CuPP framework requires the follow software to be installed:
 * - <a href="http://www.cmake.org">CMake</a>, to generate the build script
 * - <a href="http://www.nvidia.com/object/cuda_home.html">CUDA</a> version 1.1
 * 
 * \subsection build Building the CuPP framework
 * Detail instructions of how to build CuPP are included in the download file. If you have any problems
 * join us at our google group.
 * 
 * \subsection example Examples
 * Examples are included in the download file in the subdirectory 'examples'.
 * 
 * \subsection limit Known limitation
 * - The number of parameters that can be passed to a kernel is limited by the function arity supported
 *   by function_traits of Boost.TypeTraits. The version included in the download file supports an
 *   arity of 16.
 *
 * \section overview Overview
 * <img src="static/overview.png">
 * The CuPP framework consists of 5 highly interwoven parts of which some replace the existing CUDA counterparts
 * whereas other offer new functionality.
 * - <b>Device management</b> \n
 *   Device management is not done implicit by associating a thread with a
 *   device as it was done by CUDA. Instead, the developer is forced to create a
 *   device handle (cupp::device), which is passed to all CuPP functions using
 *   the device, e.g. kernel calls and memory allocation.
 * - <b>Memory management</b> \n
 *   Two different memory management concepts are available.
 *   - One is identical to the one offered by CUDA, unless that
 *     exceptions are thrown when an error occurs instead of returning an error code.
 *     To ease the development with this basic approach, a boost library-compliant
 *     shared pointer for global memory is supplied.
 *   - The second type of memory management uses a class called cupp::memory1d.
 *     Objects of this class represent a linear block of global memory. The memory is
 *     allocated when the object is created and freed when the object is destroyed.
 *     Data can be transferred to the memory from any data structure supporting iterators.
 * - <b>C++ kernel call</b> \n
 *   The CuPP kernel call is implemented by a C++ functor (cupp::kernel), which
 *   adds a call by reference like semantic to basic CUDA kernel calls. This can be used
 *   to pass datastructures like cupp::vector to a kernel, so the device can modify them.
 * - <b>Support for classes</b> \n
 *   Using a technique called "type transformations" generic C++ classes can easily be transferred to
 *   and from device memory.
 * - <b>Data structures</b> \n
 *   Currently only a std::vector wrapper offering automatic memory
 *   management is supplied. This class also implements a feature called lazy memory copying, which
 *   minimizes any memory transfers between device and host memory. Currently no other datastructure are
 *   supplied, but can be added easily.
 *
 * A document describing the functionality in detail, can be found in the references section.
 * 
 *
 * 
 * \section ref References
 * An detail description of the CuPP framework can be found in:
 * - J. Breitbart. A framework for easy CUDA integration in C++ applications.
 *   Diplomarbeit, University of Kassel, 2008. http://cupp.gpuified.de/static/thesis.pdf
 * 
 * At the time of writting no application using the CuPP framework has been released to public.
 * Some experience can be found in the thesis linked above, but the information should be expected
 * to be biased.
 * 
 * \section credit Credits
 * 
 * \subsection developer Developers in alphabetical order
 * - Jens Breitbart
 * - <a href="http://www.plm.eecs.uni-kassel.de/plm/index.php?id=bknafla">Björn Knafla</a>,
 *   University of Kassel,
 *   <a href="http://www.plm.eecs.uni-kassel.de/plm/">Research Group Programming Languages / Methodologies</a>
 * 
 * \subsection ack Acknowledgments fly out to
 * - <a href="http://www.sci.utah.edu/~abe/">Abe Stephens</a> for his very usefull CUDA CMake
 *   <a href="http://www.sci.utah.edu/~abe/FindCuda.html">script</a>.
 * - Everyone working on the <a href="http://www.boost.org/">Boost Libraries</a> for the
 *   powerful yet easy to use libraries.
 * - comp.lang.c++.moderated for some enlightening C++ code snippets.
 * 
 * \section licences Software License
 * The CuPP framework is licenced under the BSD licence. The detailed license is
 * included in the downloadable file.
 */

