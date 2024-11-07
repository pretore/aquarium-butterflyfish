#ifndef _BUTTERFLYFISH_SWAPPABLE_LIST_I_H_
#define _BUTTERFLYFISH_SWAPPABLE_LIST_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "swappable_i.h"
#include "ordered_list_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_LIST_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SWAPPABLE_I_ERROR_OTHER_IS_NULL

struct butterflyfish_swappable_list_i {
    int (*const as_ordered_list)(
            const struct butterflyfish_swappable_list_i *object,
            const struct butterflyfish_ordered_list_i **out);

    int (*const as_swappable)(
            const struct butterflyfish_swappable_list_i *object,
            struct butterflyfish_swappable_i **out);
};

/**
 * @brief Return swappable list as a stream.
 * @param [in] object swappable list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_stream(
        const struct butterflyfish_swappable_list_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return swappable list as a collection.
 * @param [in] object swappable list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_collection(
        const struct butterflyfish_swappable_list_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return swappable list as a list.
 * @param [in] object swappable list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_list(
        const struct butterflyfish_swappable_list_i *object,
        const struct butterflyfish_list_i **out);

/**
 * @brief Return swappable list as an ordered.
 * @param [in] object swappable list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_ordered(
        const struct butterflyfish_swappable_list_i *object,
        const struct butterflyfish_ordered_i **out);

/**
 * @brief Return swappable list as a swappable.
 * @param [in] object swappable list instance.
 * @param [out] out receive swappable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_swappable(
        struct butterflyfish_swappable_list_i *object,
        struct butterflyfish_swappable_i **out);

/**
 * @brief Return swappable list as an ordered list.
 * @param [in] object swappable list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_as_ordered_list(
        const struct butterflyfish_swappable_list_i *object,
        const struct butterflyfish_ordered_list_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_count(
        const struct butterflyfish_swappable_list_i *object,
        uintmax_t *out);

/**
 * @brief First item of the list.
 * @param [in] object swappable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_swappable_list_i_first(
        const struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the list.
 * @param [in] object swappable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_swappable_list_i_last(
        const struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object swappable list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_swappable_list_i_next(
        const struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object swappable list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_swappable_list_i_prev(
        const struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object swappable list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the list.
 */
int butterflyfish_swappable_list_i_get(
        const struct butterflyfish_swappable_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer **out);

/**
 * @brief Get index of item.
 * @param [in] object swappable list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_NOT_FOUND if item is not
 * contained within the list.
 */
int butterflyfish_swappable_list_i_at(
        const struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer *item,
        uintmax_t *out);

/**
 * @brief Swap the two items.
 * @param [in] object set instance.
 * @param [in] item first item.
 * @param [in] other other item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_LIST_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_list_i_swap(
        struct butterflyfish_swappable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *other);

#endif /* _BUTTERFLYFISH_SWAPPABLE_LIST_I_H_ */
