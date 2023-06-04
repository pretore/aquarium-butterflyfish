#ifndef _BUTTERFLYFISH_REDUCIBLE_STACK_WR_H_
#define _BUTTERFLYFISH_REDUCIBLE_STACK_WR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_wr.h"

struct triggerfish_weak;

#define BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_STACK_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_WR_ERROR_END_OF_SEQUENCE

struct butterflyfish_reducible_stack_wr {
    const struct butterflyfish_collection_wr collection_wr;

    int (*const pop)(void *object,
                     struct triggerfish_weak **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_reducible_stack_wr_count(
        const struct butterflyfish_reducible_stack_wr *object,
        uintmax_t *out);

/**
 * @brief First item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_STACK_IS_EMPTY if stack is empty.
 */
int butterflyfish_reducible_stack_wr_first(
        const struct butterflyfish_reducible_stack_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Last item of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_STACK_IS_EMPTY if stack is
 * empty.
 */
int butterflyfish_reducible_stack_wr_last(
        const struct butterflyfish_reducible_stack_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve next item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_END_OF_SEQUENCE if there is
 * no next item.
 */
int butterflyfish_reducible_stack_wr_next(
        const struct butterflyfish_reducible_stack_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object stack instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_END_OF_SEQUENCE if there is
 * no previous item.
 */
int butterflyfish_reducible_stack_wr_prev(
        const struct butterflyfish_reducible_stack_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Pop value off the top of the stack.
 * @param [in] object stack instance.
 * @param [out] out receive value on the top of the stack.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_REDUCIBLE_STACK_WR_ERROR_STACK_IS_EMPTY if stack is
 * empty.
 */
int butterflyfish_reducible_stack_wr_pop(
        struct butterflyfish_reducible_stack_wr *object,
        struct triggerfish_weak **out);

#endif /* _BUTTERFLYFISH_REDUCIBLE_STACK_WR_H_ */
