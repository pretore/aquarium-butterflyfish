#ifndef _BUTTERFLYFISH_SORTED_MAP_NI_NI_H_
#define _BUTTERFLYFISH_SORTED_MAP_NI_NI_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "ordered_map_ni_ni.h"

struct butterflyfish_stream_ni;
struct butterflyfish_set_ni;
struct butterflyfish_reducible_list_ni;

#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_FUNCTION_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_FUNCTION_IS_NULL

struct butterflyfish_sorted_map_ni_ni {
    const struct butterflyfish_ordered_map_ni_ni ordered_map_ni_ni;

    int (*const ceiling)(const void *object,
                         const uintmax_t key,
                         const uintmax_t *out);

    int (*const floor)(const void *object,
                       const uintmax_t key,
                       const uintmax_t *out);

    int (*const higher)(const void *object,
                        const uintmax_t key,
                        const uintmax_t *out);

    int (*const lower)(const void *object,
                       const uintmax_t key,
                       const uintmax_t *out);

    int (*const ceiling_entry)(const void *object,
                               const uintmax_t key,
                               struct butterflyfish_map_entry_ni_ni **out);

    int (*const floor_entry)(const void *object,
                             const uintmax_t key,
                             struct butterflyfish_map_entry_ni_ni **out);

    int (*const higher_entry)(const void *object,
                              const uintmax_t key,
                              struct butterflyfish_map_entry_ni_ni **out);

    int (*const lower_entry)(const void *object,
                             const uintmax_t key,
                             struct butterflyfish_map_entry_ni_ni **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_ni_ni_count(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t *out);

/**
 * @brief First entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_sorted_map_ni_ni_first(
        const struct butterflyfish_sorted_map_ni_ni *object,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Last entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_sorted_map_ni_ni_last(
        const struct butterflyfish_sorted_map_ni_ni *object,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE if there is no
 * next entry.
 */
int butterflyfish_sorted_map_ni_ni_next(
        const struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_map_entry_ni_ni *entry,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE if there is no
 * previous entry.
 */
int butterflyfish_sorted_map_ni_ni_prev(
        const struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_map_entry_ni_ni *entry,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Remove entry.
 * @param [in] object map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL if entry is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_ni_ni_remove_entry(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_map_entry_ni_ni *entry);

/**
 * @brief Remove all entries.
 * @param [in] object map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_ni_ni_remove_all_entries(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni_ni *other);

/**
 * @brief Associate value with key, if key is not already present.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS if key is
 * already present in the map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to associate value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_add(
        struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        uintmax_t value);

/**
 * @brief Associate value with key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_put(
        struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        uintmax_t value);

/**
 * @brief Replace value for existing key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key is not
 * present in the map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_replace(
        struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        uintmax_t value);

/**
 * @brief Remove key-value association.
 * @param [in] object map instance.
 * @param [in] key of key-value association to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_remove(
        struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key);

/**
 * @brief Add all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be added, ignoring duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_add_all(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni_ni *other);

/**
 * @brief Set all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_put_all(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni_ni *other);

/**
 * @brief Replace all existing key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_sorted_map_ni_ni_replace_all(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni_ni *other);

/**
 * @brief Remove all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will remove matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_remove_all(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Retain all the entries that have matching keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will retain matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_retain_all(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni *other);

/**
 * @brief Add entries into map, perform action on duplicate key.
 * @param [in] object map instance.
 * @param [in] other stream of entries that will be merged into map.
 * @param [in] function to resolve duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_FUNCTION_IS_NULL if function is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to add key-value association.
 * @note <b>function</b>'s error will be returned if present.
 */
int butterflyfish_sorted_map_ni_ni_merge(
        struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni_ni *other,
        int (*function)(
                const uintmax_t,
                const uintmax_t,
                uintmax_t *));

/**
 * @brief Check if key is present.
 * @param [in] object map instance.
 * @param [in] key whose presence is being checked.
 * @param [out] out receive true if present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_contains_key(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        bool *out);

/**
 * @brief Check if all keys are present.
 * @param [in] object map instance.
 * @param [in] other stream of keys to be checked for presence.
 * @param [out] out receive true if all are present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL if other is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup keys.
 */
int butterflyfish_sorted_map_ni_ni_contains_all_keys(
        const struct butterflyfish_sorted_map_ni_ni *object,
        const struct butterflyfish_stream_ni *other,
        bool *out);

/**
 * @brief Retrieve value for key.
 * @param [in] object map instance.
 * @param [in] key for value.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_get(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        const uintmax_t *out);

/**
 * @brief Retrieve value for key or next higher key.
 * @param [in] object map instance.
 * @param [in] key to find or the next higher key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_ceiling(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        const uintmax_t *out);

/**
 * @brief Retrieve value for key or next lower key.
 * @param [in] object map instance.
 * @param [in] key to find or the next lower key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_floor(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        const uintmax_t *out);

/**
 * @brief Retrieve value for next higher key.
 * @param [in] object map instance.
 * @param [in] key to find the next higher key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_higher(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        const uintmax_t *out);

/**
 * @brief Retrieve value for next lower key.
 * @param [in] object map instance.
 * @param [in] key to find the next lower key.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_lower(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        const uintmax_t *out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key for entry.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_get_entry(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve entry for key or next higher key.
 * @param [in] object map instance.
 * @param [in] key to find or the next higher key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_ceiling_entry(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve entry for key or next lower key.
 * @param [in] object map instance.
 * @param [in] key to find or the next lower key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_floor_entry(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve entry for next higher key.
 * @param [in] object map instance.
 * @param [in] key to find the next higher key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_higher_entry(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Retrieve entry for next lower key.
 * @param [in] object map instance.
 * @param [in] key to find the next lower key.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND if key not found
 * in map.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED if
 * there is insufficient memory to lookup key.
 */
int butterflyfish_sorted_map_ni_ni_lower_entry(
        const struct butterflyfish_sorted_map_ni_ni *object,
        uintmax_t key,
        struct butterflyfish_map_entry_ni_ni **out);

/**
 * @brief Set view of map keys.
 * @param [in] object map instance.
 * @param [out] out receive set view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_ni_ni_keys(
        struct butterflyfish_sorted_map_ni_ni *object,
        struct butterflyfish_set_ni **out);

/**
 * @brief Reducible list view of map values.
 * @param [in] object map instance.
 * @param [out] out receive reducible list view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_sorted_map_ni_ni_values(
        struct butterflyfish_sorted_map_ni_ni *object,
        struct butterflyfish_reducible_list_ni **out);

#endif /* _BUTTERFLYFISH_SORTED_MAP_NI_NI_H_ */
