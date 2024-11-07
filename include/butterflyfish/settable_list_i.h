#ifndef _BUTTERFLYFISH_SETTABLE_LIST_I_H_
#define _BUTTERFLYFISH_SETTABLE_LIST_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "list_i.h"
#include "settable_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_LIST_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_LIST_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_LIST_IS_EMPTY \
    BUTTERFLYFISH_LIST_I_ERROR_LIST_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_LIST_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_LIST_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS \
    BUTTERFLYFISH_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_NOT_FOUND \
    BUTTERFLYFISH_LIST_I_ERROR_ITEM_NOT_FOUND
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_settable_list_i {
    int (*const as_settable)(struct butterflyfish_settable_list_i *object,
                             struct butterflyfish_settable_i **out);

    int (*const as_list)(const struct butterflyfish_settable_list_i *object,
                         const struct butterflyfish_list_i **out);

    int (*const set)(struct butterflyfish_settable_list_i *object,
                     uintmax_t at,
                     const struct sea_turtle_integer *value);
};

/**
 * @brief Return settable list as a stream.
 * @param [in] object settable list instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_list_i_as_stream(
        const struct butterflyfish_settable_list_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return settable list as a collection.
 * @param [in] object settable list instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_list_i_as_collection(
        const struct butterflyfish_settable_list_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return settable list as a settable.
 * @param [in] object settable list instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_list_i_as_settable(
        struct butterflyfish_settable_list_i *object,
        struct butterflyfish_settable_i **out);

/**
 * @brief Return settable list as a list.
 * @param [in] object settable list instance.
 * @param [out] out receive list.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_list_i_as_list(
        const struct butterflyfish_settable_list_i *object,
        const struct butterflyfish_list_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_settable_list_i_count(
        const struct butterflyfish_settable_list_i *object,
        uintmax_t *out);

/**
 * @brief First item of the settable list.
 * @param [in] object settable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_settable_list_i_first(
        const struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the settable list.
 * @param [in] object settable list instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_LIST_IS_EMPTY if list is empty.
 */
int butterflyfish_settable_list_i_last(
        const struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object settable list instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_settable_list_i_next(
        const struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object settable list instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_settable_list_i_prev(
        const struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item at index.
 * @param [in] object settable list instance.
 * @param [in] at index of item to retrieve.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the list.
 */
int butterflyfish_settable_list_i_get(
        const struct butterflyfish_settable_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer **out);

/**
 * @brief Get index of item.
 * @param [in] object settable list instance.
 * @param [in] item whose index we are to determine.
 * @param [out] out receive index of item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_NOT_FOUND if item is not
 * contained within the list.
 */
int butterflyfish_settable_list_i_at(
        const struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer *item,
        uintmax_t *out);

/**
 * @brief Set value for item.
 * @param [in] object settable list instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_settable_list_i_set_item(
        struct butterflyfish_settable_list_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Set value of item at index.
 * @param [in] object settable list instance.
 * @param [in] at index of item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_INDEX_IS_OUT_OF_BOUNDS if at
 * does not refer to an item contained within the list.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is not enough memory to set the item to value.
 * @throws BUTTERFLYFISH_SETTABLE_LIST_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @note <b>value</b> is copied and then item at index is set to it.
 */
int butterflyfish_settable_list_i_set(
        struct butterflyfish_settable_list_i *object,
        uintmax_t at,
        const struct sea_turtle_integer *value);

#endif /* _BUTTERFLYFISH_SETTABLE_LIST_I_H_ */
