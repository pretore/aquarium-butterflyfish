#ifndef _BUTTERFLYFISH_ORDERED_SET_SR_H_
#define _BUTTERFLYFISH_ORDERED_SET_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "set_sr.h"

struct triggerfish_strong;

#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SET_SR_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_SR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_SR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SET_SR_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_SR_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND \
    SEA_URCHIN_ERROR_ITEM_NOT_FOUND

struct butterflyfish_ordered_set_sr {
    const struct butterflyfish_set_sr set_sr;
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_sr_count(
        const struct butterflyfish_ordered_set_sr *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_sr_first(
        const struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Last item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_sr_last(
        const struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong **out);

/**
 * @brief Remove item.
 * @param [in] object ordered set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_set_sr_remove_item(
        struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong *item);

/**
 * @brief Remove all items.
 * @param [in] object ordered set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_set_sr_remove_all_items(
        struct butterflyfish_ordered_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_ordered_set_sr_next(
        const struct butterflyfish_ordered_set_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_ordered_set_sr_prev(
        const struct butterflyfish_ordered_set_sr *object,
        const struct triggerfish_strong *item,
        struct triggerfish_strong **out);

/**
 * @brief Add value to the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present in the ordered set.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add value to the ordered set.
 */
int butterflyfish_ordered_set_sr_add(
        struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong *value);

/**
 * @brief Add values to the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be added, ignoring duplicates.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add streamed values to the ordered set.
 */
int butterflyfish_ordered_set_sr_add_all(
        struct butterflyfish_ordered_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Remove value from the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND if value is not
 * in the ordered set instance.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_ordered_set_sr_remove(
        struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong *value);

/**
 * @brief Remove values from the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be removed, ignoring value not
 * found.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the streamed values in the ordered set.
 */
int butterflyfish_ordered_set_sr_remove_all(
        struct butterflyfish_ordered_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Check if ordered set contains the given value.
 * @param [in] object ordered set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_sr_contains(
        const struct butterflyfish_ordered_set_sr *object,
        struct triggerfish_strong *value,
        bool *out);

/**
 * @brief Check if ordered set contains all the given values.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_sr_contains_all(
        const struct butterflyfish_ordered_set_sr *object,
        const struct butterflyfish_stream_sr *other,
        bool *out);

/**
 * @brief Retain all the values present in both.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values, if present in ordered set too, will
 * be retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_sr_retain_all(
        struct butterflyfish_ordered_set_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Retrieve item for value.
 * @param [in] object ordered set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND if there is no
 * item that matched value.
 * @throws BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_sr_get(
        const struct butterflyfish_ordered_set_sr *object,
        const struct triggerfish_strong *value,
        struct triggerfish_strong **out);

#endif /* _BUTTERFLYFISH_ORDERED_SET_SR_H_ */
