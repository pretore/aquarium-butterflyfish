#ifndef _BUTTERFLYFISH_SWAPPABLE_I_H_
#define _BUTTERFLYFISH_SWAPPABLE_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "ordered_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_SWAPPABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SWAPPABLE_I_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL

struct butterflyfish_swappable_i {
    int (*const as_ordered)(const struct butterflyfish_swappable_i *object,
                            const struct butterflyfish_ordered_i **out);

    int (*const swap)(struct butterflyfish_swappable_i *object,
                      const struct sea_turtle_integer *item,
                      const struct sea_turtle_integer *other);
};

/**
 * @brief Return swappable as a stream.
 * @param [in] object swappable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_swappable_i_as_stream(
        const struct butterflyfish_swappable_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return swappable as a collection.
 * @param [in] object swappable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_swappable_i_as_collection(
        const struct butterflyfish_swappable_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return swappable as ordered.
 * @param [in] object swappable instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_swappable_i_as_ordered(
        const struct butterflyfish_swappable_i *object,
        const struct butterflyfish_ordered_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_swappable_i_count(
        const struct butterflyfish_swappable_i *object,
        uintmax_t *out);

/**
 * @brief First item of swappable.
 * @param [in] object swappable instance.
 * @param [out] out receive the first item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_SWAPPABLE_IS_EMPTY if swappable is
 * empty.
 */
int butterflyfish_swappable_i_first(
        const struct butterflyfish_swappable_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of swappable.
 * @param [in] object swappable instance.
 * @param [out] out receive the last item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_SWAPPABLE_IS_EMPTY if swappable is
 * empty.
 */
int butterflyfish_swappable_i_last(
        const struct butterflyfish_swappable_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object swappable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_swappable_i_next(
        const struct butterflyfish_swappable_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object swappable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_swappable_i_prev(
        const struct butterflyfish_swappable_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Swap the two items.
 * @param [in] object swappable instance.
 * @param [in] item first item.
 * @param [in] other other item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_i_swap(
        struct butterflyfish_swappable_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *other);

#endif /* _BUTTERFLYFISH_SWAPPABLE_I_H_ */
