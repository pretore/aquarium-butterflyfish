#ifndef _BUTTERFLYFISH_REDUCIBLE_STACK_NI_H_
#define _BUTTERFLYFISH_REDUCIBLE_STACK_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_ni.h"

#define BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_STACK_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE

struct butterflyfish_reducible_stack_ni {
    const struct butterflyfish_collection_ni collection_ni;

    int (*const pop)(void *object,
                     uintmax_t *out);
};

/**
 * @brief Return reducible stack as a stream.
 * @param [in] object reducible stack instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_stack_ni_as_stream(
        const struct butterflyfish_reducible_stack_ni *object,
        const struct butterflyfish_stream_ni **out);

/**
 * @brief Return reducible stack as a collection.
 * @param [in] object reducible stack instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_stack_ni_as_collection(
        const struct butterflyfish_reducible_stack_ni *object,
        const struct butterflyfish_collection_ni **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_stack_ni_count(
        const struct butterflyfish_reducible_stack_ni *object,
        uintmax_t *out);

/**
 * @brief First item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_STACK_IS_EMPTY if stack is
 * empty.
 */
int butterflyfish_reducible_stack_ni_first(
        const struct butterflyfish_reducible_stack_ni *object,
        const uintmax_t **out);

/**
 * @brief Last item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_STACK_IS_EMPTY if stack is
 * empty.
 */
int butterflyfish_reducible_stack_ni_last(
        const struct butterflyfish_reducible_stack_ni *object,
        const uintmax_t **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_END_OF_SEQUENCE if there is
 * no next item.
 */
int butterflyfish_reducible_stack_ni_next(
        const struct butterflyfish_reducible_stack_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_END_OF_SEQUENCE if there is
 * no previous item.
 */
int butterflyfish_reducible_stack_ni_prev(
        const struct butterflyfish_reducible_stack_ni *object,
        const uintmax_t *item,
        const uintmax_t **out);

/**
 * @brief Pop value off the top of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive value on the top of the stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_NI_ERROR_STACK_IS_EMPTY if stack is
 * empty.
 */
int butterflyfish_reducible_stack_ni_pop(
        struct butterflyfish_reducible_stack_ni *object,
        uintmax_t *out);

#endif /* _BUTTERFLYFISH_REDUCIBLE_STACK_NI_H_ */
