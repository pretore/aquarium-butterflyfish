#ifndef _BUTTERFLYFISH_SORTED_MAP_I_I_H_
#define _BUTTERFLYFISH_SORTED_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_map_i_i.h"

struct sea_turtle_integer;
struct butterflyfish_stream_i;
struct butterflyfish_sorted_set_i;
struct butterflyfish_reducible_list_i;

#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_FUNCTION_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_FUNCTION_IS_NULL

struct butterflyfish_sorted_map_i_i {
    const struct butterflyfish_ordered_map_i_i ordered_map_i_i;

    int (*const first)(const void *object,
                       const struct butterflyfish_map_entry_i_i **out);

    int (*const next)(const void *object,
                      const struct butterflyfish_map_entry_i_i *entry,
                      const struct butterflyfish_map_entry_i_i **out);

    int (*const last)(const void *object,
                      const struct butterflyfish_map_entry_i_i **out);

    int (*const prev)(const void *object,
                      const struct butterflyfish_map_entry_i_i *entry,
                      const struct butterflyfish_map_entry_i_i **out);

    int (*const keys)(void *object,
                      struct butterflyfish_sorted_set_i **out);

    int (*const ceiling)(const void *object,
                         const struct sea_turtle_integer *key,
                         const struct sea_turtle_integer **out);

    int (*const floor)(const void *object,
                       const struct sea_turtle_integer *key,
                       const struct sea_turtle_integer **out);

    int (*const higher)(const void *object,
                        const struct sea_turtle_integer *key,
                        const struct sea_turtle_integer **out);

    int (*const lower)(const void *object,
                       const struct sea_turtle_integer *key,
                       const struct sea_turtle_integer **out);

    int (*const ceiling_entry)(const void *object,
                               const struct sea_turtle_integer *key,
                               const struct butterflyfish_map_entry_i_i **out);

    int (*const floor_entry)(const void *object,
                             const struct sea_turtle_integer *key,
                             const struct butterflyfish_map_entry_i_i **out);

    int (*const higher_entry)(const void *object,
                              const struct sea_turtle_integer *key,
                              const struct butterflyfish_map_entry_i_i **out);

    int (*const lower_entry)(const void *object,
                             const struct sea_turtle_integer *key,
                             const struct butterflyfish_map_entry_i_i **out);
};

/**
 * @brief Return sorted map as a stream.
 * @param [in] object sorted map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_as_stream(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return sorted map as a collection.
 * @param [in] object sorted map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_as_collection(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Return sorted map as a map.
 * @param [in] object sorted map instance.
 * @param [out] out receive map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_as_map(
        struct butterflyfish_sorted_map_i_i *object,
        struct butterflyfish_map_i_i **out);

/**
 * @brief Return sorted map as a map.
 * @param [in] object sorted map instance.
 * @param [out] out receive ordered map.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_as_ordered_map(
        struct butterflyfish_sorted_map_i_i *object,
        struct butterflyfish_ordered_map_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_count(
        const struct butterflyfish_sorted_map_i_i *object,
        uintmax_t *out);

/**
 * @brief First entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_sorted_map_i_i_first(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Last entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_sorted_map_i_i_last(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next entry.
 */
int butterflyfish_sorted_map_i_i_next(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous entry.
 */
int butterflyfish_sorted_map_i_i_prev(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Remove entry.
 * @param [in] object map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_remove_entry(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_map_entry_i_i *entry);

/**
 * @brief Remove all entries.
 * @param [in] object map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_remove_all_entries(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Associate value with key, if key is not already present.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key is
 * already present in the map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to associate value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_sorted_map_i_i_add(
        struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Associate value with key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_sorted_map_i_i_put(
        struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Replace value for existing key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * present in the map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_sorted_map_i_i_replace(
        struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer *value);

/**
 * @brief Remove key-value association.
 * @param [in] object map instance.
 * @param [in] key of key-value association to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key is not
 * present in the map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_remove(
        struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key);

/**
 * @brief Add all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be added, ignoring duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_sorted_map_i_i_add_all(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Set all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_sorted_map_i_i_put_all(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Replace all existing key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_sorted_map_i_i_replace_all(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i *other);

/**
 * @brief Remove all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will remove matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_remove_all(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Retain all the entries that have matching keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will retain matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_retain_all(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Add entries into map, perform action on duplicate key.
 * @param [in] object map instance.
 * @param [in] other stream of entries that will be merged into map.
 * @param [in] function to resolve duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_FUNCTION_IS_NULL if function is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add key-value association.
 * @note <b>function</b>'s error will be returned if present.
 */
int butterflyfish_sorted_map_i_i_merge(
        struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i_i *other,
        int (*function)(
                const struct sea_turtle_integer *,
                const struct sea_turtle_integer *,
                struct sea_turtle_integer **));

/**
 * @brief Check if key is present.
 * @param [in] object map instance.
 * @param [in] key whose presence is being checked.
 * @param [out] out receive true if present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_contains_key(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        bool *out);

/**
 * @brief Check if all keys are present.
 * @param [in] object map instance.
 * @param [in] other stream of keys to be checked for presence.
 * @param [out] out receive true if all are present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup keys.
 */
int butterflyfish_sorted_map_i_i_contains_all_keys(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve value for key.
 * @param [in] object map instance.
 * @param [in] key for value.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_get(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve value for key or next higher key.
 * @param [in] object map instance.
 * @param [in] key to find or the next higher key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_ceiling(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve value for key or next lower key.
 * @param [in] object map instance.
 * @param [in] key to find or the next lower key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_floor(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve value for next higher key.
 * @param [in] object map instance.
 * @param [in] key to find the next higher key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_higher(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve value for next lower key.
 * @param [in] object map instance.
 * @param [in] key to find the next lower key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_lower(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key for entry.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_get_entry(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve entry for key or next higher key.
 * @param [in] object map instance.
 * @param [in] key to find or the next higher key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_ceiling_entry(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve entry for key or next lower key.
 * @param [in] object map instance.
 * @param [in] key to find or the next lower key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_floor_entry(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve entry for next higher key.
 * @param [in] object map instance.
 * @param [in] key to find the next higher key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_higher_entry(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Retrieve entry for next lower key.
 * @param [in] object map instance.
 * @param [in] key to find the next lower key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL if key is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_i_i_lower_entry(
        const struct butterflyfish_sorted_map_i_i *object,
        const struct sea_turtle_integer *key,
        const struct butterflyfish_map_entry_i_i **out);

/**
 * @brief Set view of map keys.
 * @param [in] object map instance.
 * @param [out] out receive set view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_keys(
        struct butterflyfish_sorted_map_i_i *object,
        struct butterflyfish_sorted_set_i **out);

/**
 * @brief Reducible list view of map values.
 * @param [in] object map instance.
 * @param [out] out receive reducible list view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_i_i_values(
        struct butterflyfish_sorted_map_i_i *object,
        struct butterflyfish_reducible_list_i **out);

#endif /* _BUTTERFLYFISH_SORTED_MAP_I_I_H_ */
