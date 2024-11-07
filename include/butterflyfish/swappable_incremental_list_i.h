#ifndef _BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_H_
#define _BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "swappable_list_i.h"
#include "ordered_incremental_list_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_swappable_incremental_list_i {
    int (*const as_swappable_list)(
            struct butterflyfish_swappable_incremental_list_i *object,
            struct butterflyfish_swappable_list_i **out);

    int (*const as_ordered_incremental_list)(
            struct butterflyfish_swappable_incremental_list_i *object,
            struct butterflyfish_ordered_incremental_list_i **out);
};

/**
 * @brief Return swappable incremental list as a stream.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_stream(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return swappable incremental list as a collection.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_collection(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return swappable incremental list as an ordered.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_ordered(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_ordered_i **out);

/**
 * @brief Return swappable incremental list as a list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_list(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_list_i **out);

/**
 * @brief Return swappable incremental list as an addable.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_addable(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_addable_i **out);

/**
 * @brief Return swappable incremental list as a swappable.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive swappable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_swappable(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_swappable_i **out);

/**
 * @brief Return swappable incremental list as an insertable.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_insertable(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_insertable_i **out);

/**
 * @brief Return swappable incremental list as an ordered list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive ordered list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_ordered_list(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_ordered_list_i **out);

/**
 * @brief Return swappable incremental list as an incremental list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_incremental_list(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_incremental_list_i **out);

/**
 * @brief Return swappable incremental list as an swappable list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive swappable list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_swappable_list(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_swappable_list_i **out);

/**
 * @brief Return swappable incremental list as an ordered incremental list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive ordered incremental list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_as_ordered_incremental_list(
        struct butterflyfish_swappable_incremental_list_i *object,
        struct butterflyfish_ordered_incremental_list_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_count(
        const struct butterflyfish_swappable_incremental_list_i *object,
        uintmax_t *out);

/**
 * @brief First item of the list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_swappable_incremental_list_i_first(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the list.
 * @param [in] object swappable incremental list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_LIST_IS_EMPTY if
 * list is empty.
 */
int butterflyfish_swappable_incremental_list_i_last(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object swappable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_swappable_incremental_list_i_next(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object swappable incremental list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_END_OF_SEQUENCE if
 * there is no next item.
 */
int butterflyfish_swappable_incremental_list_i_prev(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object swappable incremental list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if
 * at does not refer to an item contained within the list.
 */
int butterflyfish_swappable_incremental_list_i_get(
        const struct butterflyfish_swappable_incremental_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer **out);

/**
 * @brief Get index of item.
 * @param [in] object swappable incremental list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OUT_IS_NULL if
 * out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_NOT_FOUND if
 * item is not contained within the list.
 */
int butterflyfish_swappable_incremental_list_i_at(
        const struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        uintmax_t *out);

/**
 * @brief Swap the two items.
 * @param [in] object swappable settable list instance.
 * @param [in] item first item.
 * @param [in] other other item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 */
int butterflyfish_swappable_incremental_list_i_swap(
        struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *other);

/**
 * @brief Add value to the end.
 * @param [in] object swappable incremental list instance.
 * @param [in] value to append.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to add the value.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @note <b>value</b> is copied and then added to the end.
 */
int butterflyfish_swappable_incremental_list_i_add(
        struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object swappable incremental list instance.
 * @param [in] other stream of values which are appended.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to add the values.
 * @note Each <b>value</b> is copied and then added to the end.
 */
int butterflyfish_swappable_incremental_list_i_add_all(
        struct butterflyfish_swappable_incremental_list_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Insert value into the list.
 * @param [in] object swappable incremental list instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_NULL if
 * value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws
 * BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the list.
 * @note <b>value</b> is copied and then placed into the list.
 */
int butterflyfish_swappable_incremental_list_i_insert(
        struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Insert all the values into to the list.
 * @param [in] object swappable incremental list instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_ITEM_IS_NULL if
 * item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_OTHER_IS_NULL if
 * other is <i>NULL</i>.
 * @throws
 * BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the list.
 * @note streamed <b>values</b> are copied and then placed into the list.
 */
int butterflyfish_swappable_incremental_list_i_insert_all(
        struct butterflyfish_swappable_incremental_list_i *object,
        const struct sea_turtle_integer *item,
        const struct butterflyfish_stream_i *other);

#endif /* _BUTTERFLYFISH_SWAPPABLE_INCREMENTAL_LIST_I_H_ */
