#ifndef _BUTTERFLYFISH_STACK_NI_H_
#define _BUTTERFLYFISH_STACK_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "reducible_stack_ni.h"

#define BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STACK_NI_ERROR_STACK_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_STACK_IS_EMPTY
#define BUTTERFLYFISH_STACK_NI_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STACK_NI_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_STACK_NI_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_STACK_NI_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_STACK_NI_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_stack_ni {
    const struct butterflyfish_reducible_stack_ni reducible_stack_ni;

    int (*const push)(void *object,
                      const uintmax_t value);

    int (*const push_all)(void *object,
                          const struct butterflyfish_stream_ni *other);
};

/**
 * @brief Return stack as a collection.
 * @param [in] object stack instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_ni_as_stream(
        const struct butterflyfish_stack_ni *object,
        const struct butterflyfish_stream_ni **out);

/**
 * @brief Return stack as a collection.
 * @param [in] object stack instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_ni_as_collection(
        const struct butterflyfish_stack_ni *object,
        const struct butterflyfish_collection_ni **out);

/**
 * @brief Return stack as a reducible stack.
 * @param [in] object stack instance.
 * @param [out] out receive reducible stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_ni_as_reducible_stack(
        struct butterflyfish_stack_ni *object,
        struct butterflyfish_reducible_stack_ni **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_ni_count(
        const struct butterflyfish_stack_ni *object,
        uintmax_t *out);

/**
 * @brief First item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_ni_first(
        const struct butterflyfish_stack_ni *object,
        const uintmax_t **out);

/**
 * @brief Last item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_ni_last(
        const struct butterflyfish_stack_ni *object,
        const uintmax_t **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_stack_ni_next(
        const struct butterflyfish_stack_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_stack_ni_prev(
        const struct butterflyfish_stack_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Pop value off the top of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive value on the top of the stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_ni_pop(
        struct butterflyfish_stack_ni *object,
        uintmax_t *out);

/**
 * @brief Add value to the top of the stack.
 * @param [in] object stack instance.
 * @param [in] value to add to the top.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_VALUE_IS_INVALID if value is invalid.
 * @note <b>value</b> is copied and then added to the top of the stack.
 */
int butterflyfish_stack_ni_push(
        struct butterflyfish_stack_ni *object,
        uintmax_t value);

/**
 * @brief Add all values to the top of the stack.
 * @param [in] object stack instance.
 * @param [in] other stream of values which are added, ignoring the invalid
 * values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_NI_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and to the top of the stack.
 */
int butterflyfish_stack_ni_push_all(
        struct butterflyfish_stack_ni *object,
        const struct butterflyfish_stream_ni *other);

#endif /* _BUTTERFLYFISH_STACK_NI_H_ */
