#ifndef _BUTTERFLYFISH_ORDERED_SET_S_H_
#define _BUTTERFLYFISH_ORDERED_SET_S_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "set_s.h"

struct sea_turtle_string;

#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SET_S_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SET_S_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SET_S_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SET_S_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SET_S_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_SET_S_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SET_S_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_NOT_FOUND \
    SEA_URCHIN_ERROR_ITEM_NOT_FOUND

struct butterflyfish_ordered_set_s {
    const struct butterflyfish_set_s set_s;
};

/**
 * @brief Return ordered set as a stream.
 * @param [in] object set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_as_stream(
        const struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s **out);

/**
 * @brief Return ordered set as a collection.
 * @param [in] object ordered set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_as_collection(
        const struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_collection_s **out);

/**
 * @brief Return ordered set as a set.
 * @param [in] object ordered set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_as_set(
        struct butterflyfish_ordered_set_s *object,
        struct butterflyfish_set_s **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_count(
        const struct butterflyfish_ordered_set_s *object,
        uintmax_t *out);

/**
 * @brief First item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_s_first(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string **out);

/**
 * @brief Last item of the ordered set.
 * @param [in] object ordered set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY if ordered set is
 * empty.
 */
int butterflyfish_ordered_set_s_last(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string **out);

/**
 * @brief Remove item.
 * @param [in] object ordered set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_remove_item(
        struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *item);

/**
 * @brief Remove all items.
 * @param [in] object ordered set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_ordered_set_s_remove_all_items(
        struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Retrieve next item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_ordered_set_s_next(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *item,
        const struct sea_turtle_string **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object ordered set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_ordered_set_s_prev(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *item,
        const struct sea_turtle_string **out);

/**
 * @brief Add value to the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present in the ordered set.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add value to the ordered set.
 * @note <b>value</b> is copied and then placed into the ordered set.
 */
int butterflyfish_ordered_set_s_add(
        struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *value);

/**
 * @brief Add values to the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be added, ignoring duplicates.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add streamed values to the ordered set.
 * @note streamed <b>values</b> are copied and then placed into the ordered set.
 */
int butterflyfish_ordered_set_s_add_all(
        struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Remove value from the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_NOT_FOUND if value is not
 * in the ordered set instance.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the value.
 */
int butterflyfish_ordered_set_s_remove(
        struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *value);

/**
 * @brief Remove values from the ordered set.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be removed, ignoring value not
 * found.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the streamed values in the ordered set.
 */
int butterflyfish_ordered_set_s_remove_all(
        struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Check if ordered set contains the given value.
 * @param [in] object ordered set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_s_contains(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *value,
        bool *out);

/**
 * @brief Check if ordered set contains all the given values.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values will be checked for presence in
 * ordered set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_s_contains_all(
        const struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s *other,
        bool *out);

/**
 * @brief Retain all the values present in both.
 * @param [in] object ordered set instance.
 * @param [in] other stream whose values, if present in ordered set too, will
 * be retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_s_retain_all(
        struct butterflyfish_ordered_set_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Retrieve item for value.
 * @param [in] object ordered set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_NOT_FOUND if there is no
 * item that matched value.
 * @throws BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to find the item.
 */
int butterflyfish_ordered_set_s_get(
        const struct butterflyfish_ordered_set_s *object,
        const struct sea_turtle_string *value,
        const struct sea_turtle_string **out);

#endif /* _BUTTERFLYFISH_ORDERED_SET_S_H_ */
