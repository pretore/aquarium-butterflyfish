#ifndef _BUTTERFLYFISH_SORTED_SETTABLE_SET_I_H_
#define _BUTTERFLYFISH_SORTED_SETTABLE_SET_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "sorted_set_i.h"
#include "settable_set_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_sorted_settable_set_i {
    int (*const as_sorted_set)(
            const struct butterflyfish_sorted_settable_set_i *object,
            const struct butterflyfish_sorted_set_i **out);

    int (*const as_settable_set)(
            struct butterflyfish_sorted_settable_set_i *object,
            struct butterflyfish_settable_set_i **out);
};

/**
 * @brief Return sorted settable set as a stream.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_stream(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return sorted settable set as a collection.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_collection(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return sorted settable set as a settable.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_settable(
        struct butterflyfish_sorted_settable_set_i *object,
        struct butterflyfish_settable_i **out);

/**
 * @brief Return sorted settable set as a sorted.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive sorted.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_sorted(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_sorted_i **out);

/**
 * @brief Return sorted settable set as a set.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_set(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_set_i **out);

/**
 * @brief Return sorted settable set as a sorted set.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive sorted set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_sorted_set(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_sorted_set_i **out);

/**
 * @brief Return sorted settable set as a settable set.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_as_settable_set(
        struct butterflyfish_sorted_settable_set_i *object,
        struct butterflyfish_settable_set_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_settable_set_i_count(
        const struct butterflyfish_sorted_settable_set_i *object,
        uintmax_t *out);

/**
 * @brief First item of the sorted settable set.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_sorted_settable_set_i_first(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the sorted settable set.
 * @param [in] object sorted settable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_sorted_settable_set_i_last(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object sorted settable set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_sorted_settable_set_i_next(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object sorted settable set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_sorted_settable_set_i_prev(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Check if sorted settable set contains the given value.
 * @param [in] object sorted settable set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_contains(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if sorted settable set contains all the given values.
 * @param [in] object sorted settable set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_contains_all(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if value
 * is not in the set instance.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_get(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Set value for item.
 * @param [in] object set instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_sorted_settable_set_i_set_item(
        struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Set value for looked up item.
 * @param [in] object ordered settable set instance.
 * @param [in] item to lookup.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if item is
 * not in the set.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then the lookup item is set to it.
 */
int butterflyfish_sorted_settable_set_i_set(
        struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Retrieve item for value or the next higher value.
 * @param [in] object sorted settable set instance.
 * @param [in] value to find or its next higher.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if no
 * value in sorted settable set was equal to or higher than value.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_ceiling(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for value or the next lower value.
 * @param [in] object sorted settable set instance.
 * @param [in] value to find or its next lower.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if no
 * value in sorted settable set was equal to or lower than value.
 * @throws BUTTERFLYFISH_SORTED_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_floor(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for next higher value.
 * @param [in] object sorted settable set instance.
 * @param [in] value whose next higher value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if no
 * value in sorted settable set is greater.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_higher(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve item for the next lower value.
 * @param [in] object sorted settable set instance.
 * @param [in] value whose next lower value we are trying to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_VALUE_NOT_FOUND if no
 * value in sorted settable set is lower.
 * @throws BUTTERFLYFISH_SORTED_SETTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_sorted_settable_set_i_lower(
        const struct butterflyfish_sorted_settable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

#endif /* _BUTTERFLYFISH_SORTED_SETTABLE_SET_I_H_ */
