#ifndef _BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_H_
#define _BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_set_i_i.h"
#include "settable_set_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_ordered_settable_set_i_i {
    int (*const as_ordered_set)(
            const struct butterflyfish_ordered_settable_set_i_i *object,
            const struct butterflyfish_ordered_set_i_i **out);

    int (*const as_settable_set)(
            struct butterflyfish_ordered_settable_set_i_i *object,
            struct butterflyfish_settable_set_i_i **out);
};

/**
 * @brief Return ordered settable set as a stream.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_stream(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return ordered settable set as a collection.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_collection(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return ordered settable set as an settable.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_settable(
        struct butterflyfish_ordered_settable_set_i_i *object,
        struct butterflyfish_settable_i_i **out);

/**
 * @brief Return ordered settable set as an ordered.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_ordered(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_ordered_i_i **out);

/**
 * @brief Return ordered settable set as a set.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_set(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_set_i_i **out);

/**
 * @brief Return ordered settable set as a settable set.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_settable_set(
        struct butterflyfish_ordered_settable_set_i_i *object,
        struct butterflyfish_settable_set_i_i **out);

/**
 * @brief Return ordered settable set as an ordered set.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_as_ordered_set(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_ordered_set_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_settable_set_i_i_count(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered settable set.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_ordered_settable_set_i_i_first(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the ordered settable set.
 * @param [in] object ordered settable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_ordered_settable_set_i_i_last(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered settable set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_ordered_settable_set_i_i_next(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered settable set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_ordered_settable_set_i_i_prev(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Check if ordered settable set contains the given value.
 * @param [in] object ordered settable set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_settable_set_i_i_contains(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        bool *out);

/**
 * @brief Check if ordered settable set contains all the given values.
 * @param [in] object ordered settable set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_settable_set_i_i_contains_all(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object ordered settable set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND if
 * value is not in the set instance.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_ordered_settable_set_i_i_get(
        const struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *value,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Set value for item.
 * @param [in] object ordered settable set instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_ordered_settable_set_i_i_set_item(
        struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

/**
 * @brief Set value for looked up item.
 * @param [in] object ordered settable set instance.
 * @param [in] item to lookup.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND if item
 * is not in the set.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
  * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_VALUE_IS_INVALID if
 * value invalid.
 * @throws BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then the lookup item is set to it.
 */
int butterflyfish_ordered_settable_set_i_i_set(
        struct butterflyfish_ordered_settable_set_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

#endif /* _BUTTERFLYFISH_ORDERED_SETTABLE_SET_I_I_H_ */
