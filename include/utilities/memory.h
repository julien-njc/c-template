#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

	/**
	 * @brief Wrap the malloc C function to include nice error reporting
	 *
	 * @param size number of bytes to allocate
	 * @return void* On success, returns the pointer to the beginning of newly allocated memory.
	 * To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
	 *
	 * On failure, returns a null pointer.
	 */
	void* safe_malloc(size_t size);

	/**
	 * @brief Wrap the calloc C function to include nice error reporting
	 *
	 * @param num number of objects
	 * @param size size of each object
	 * @return void* On success, returns the pointer to the beginning of newly allocated memory.
	 * To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
	 *
	 * On failure, returns a null pointer.
	 */
	void* safe_calloc(size_t num, size_t size);

	/**
	 * @brief Wrap the realloc C function to include nice error reporting
	 *
	 * @param ptr pointer to the memory area to be reallocated
	 * @param new_size new size of the array in bytes
	 * @return void* On success, returns the pointer to the beginning of newly allocated memory.
	 * To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
	 * The original pointer ptr is invalidated and any access to it is undefined behavior (even if reallocation was
	 * in-place).
	 *
	 * On failure, returns a null pointer. The original pointer ptr remains valid and may need to be deallocated with
	 * free() or realloc().
	 */
	void* safe_realloc(void* ptr, size_t new_size);

	/**
	 * @brief Wrap the aligned_alloc C function to include nice error reporting
	 *
	 * @param alignment specifies the alignment. Must be a valid alignment supported by the implementation.
	 * @param size number of bytes to allocate. An integral multiple of alignment
	 * @return void* On success, returns the pointer to the beginning of newly allocated memory.
	 * To avoid a memory leak, the returned pointer must be deallocated with free() or realloc().
	 *
	 * On failure, returns a null pointer.
	 */
	void* safe_aligned_alloc(size_t alignment, size_t size);

	/**
	 * @brief Wrap the free C function to set the pointer to NULL after it has been freed
	 *
	 * @param ptr
	 */
	void safe_free(void** ptr);

#ifdef __cplusplus
} // extern "C"
#endif
