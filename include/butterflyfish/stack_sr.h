#ifndef _BUTTERFLYFISH_STACK_SR_H_
#define _BUTTERFLYFISH_STACK_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "reducible_stack_sr.h"

struct triggerfish_strong;

#define BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_STACK_IS_EMPTY
#define BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_STACK_SR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_STACK_SR_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID


struct butterflyfish_stack_sr {
    const struct butterflyfish_reducible_stack_sr reducible_stack_sr;

    int (*const push)(void *object,
                      struct triggerfish_strong *value);

    int (*const push_all)(void *object,
                          const struct butterflyfish_stream_sr *other);
};

/**
 * @brief Return stack as a collection.
 * @param [in] object stack instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_sr_as_stream(
        const struct butterflyfish_stack_sr *object,
        const struct butterflyfish_stream_sr **out);

/**
 * @brief Return stack as a collection.
 * @param [in] object stack instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_sr_as_collection(
        const struct butterflyfish_stack_sr *object,
        const struct butterflyfish_collection_sr **out);

/**
 * @brief Return stack as a reducible stack.
 * @param [in] object stack instance.
 * @param [out] out receive reducible stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_sr_as_reducible_stack(
        struct butterflyfish_stack_sr *object,
        struct butterflyfish_reducible_stack_sr **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_stack_sr_count(
        const struct butterflyfish_stack_sr *object,
        uintmax_t *out);

/**
 * @brief First item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_sr_first(
        const struct butterflyfish_stack_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Last item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_sr_last(
        const struct butterflyfish_stack_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_stack_sr_next(
        const struct butterflyfish_stack_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_stack_sr_prev(
        const struct butterflyfish_stack_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Pop value off the top of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive value on the top of the stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_stack_sr_pop(
        struct butterflyfish_stack_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Add value to the top of the stack.
 * @param [in] object stack instance.
 * @param [in] value to add to the top.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @throws BUTTERFLYFISH_STACK_I_ERROR_VALUE_IS_INVALID if value is invalid.
 */
int butterflyfish_stack_sr_push(
        struct butterflyfish_stack_sr *object,
        struct triggerfish_strong *value);

/**
 * @brief Add all values to the top of the stack.
 * @param [in] object stack instance.
 * @param [in] other stream of values which are added, ignoring the invalid
 * values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_STACK_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 */
int butterflyfish_stack_sr_push_all(
        struct butterflyfish_stack_sr *object,
        const struct butterflyfish_stream_sr *other);

#endif /* _BUTTERFLYFISH_STACK_SR_H_ */
