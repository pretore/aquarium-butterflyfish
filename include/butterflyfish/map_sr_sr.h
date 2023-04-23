#ifndef _BUTTERFLYFISH_MAP_SR_SR_H_
#define _BUTTERFLYFISH_MAP_SR_SR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_sr_sr.h"

struct triggerfish_strong;
struct butterflyfish_stream_sr;
struct butterflyfish_set_sr;
struct butterflyfish_reducible_list_sr;

#define BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_SR_SR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL \
    SEA_URCHIN_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_SR_SR_ERROR_FUNCTION_IS_NULL \
    SEA_URCHIN_ERROR_FUNCTION_IS_NULL

struct butterflyfish_map_sr_sr {
    const struct butterflyfish_collection_sr_sr collection_sr_sr;

    int (*const add)(void *object,
                     struct triggerfish_strong *key,
                     struct triggerfish_strong *value);

    int (*const put)(void *object,
                     struct triggerfish_strong *key,
                     struct triggerfish_strong *value);

    int (*const replace)(void *object,
                         struct triggerfish_strong *key,
                         struct triggerfish_strong *value);

    int (*const remove)(void *object,
                        struct triggerfish_strong *key);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_sr_sr *other);

    int (*const put_all)(void *object,
                         const struct butterflyfish_stream_sr_sr *other);

    int (*const replace_all)(void *object,
                             const struct butterflyfish_stream_sr_sr *other);

    int (*const remove_all)(void *object,
                            const struct butterflyfish_stream_sr *other);

    int (*const retain_all)(void *object,
                            const struct butterflyfish_stream_sr *other);

    int (*const merge)(void *object,
                       const struct butterflyfish_stream_sr_sr *other,
                       int (*function)(
                               const struct triggerfish_strong *,
                               const struct triggerfish_strong *,
                               struct triggerfish_strong **));

    int (*const remove_entry)(void *object,
                              const struct butterflyfish_map_entry_sr_sr *entry);

    int (*const remove_all_entries)(void *object,
                                    const struct butterflyfish_stream_sr_sr *other);

    int (*const contains_key)(const void *object,
                              struct triggerfish_strong *key,
                              bool *out);

    int (*const contains_all_keys)(const void *object,
                                   const struct butterflyfish_stream_sr *other,
                                   bool *out);

    int (*const get)(const void *object,
                     struct triggerfish_strong *key,
                     struct triggerfish_strong **out);

    int (*const get_entry)(const void *object,
                           struct triggerfish_strong *key,
                           struct butterflyfish_map_entry_sr_sr **out);

    int (*const keys)(void *object,
                      struct butterflyfish_set_sr **out);

    int (*const values)(void *object,
                        struct butterflyfish_reducible_list_sr **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_sr_sr_count(
        const struct butterflyfish_map_sr_sr *object,
        uintmax_t *out);

/**
 * @brief First entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_sr_sr_first(
        const struct butterflyfish_map_sr_sr *object,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Last entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_sr_sr_last(
        const struct butterflyfish_map_sr_sr *object,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE if there is no next
 * entry.
 */
int butterflyfish_map_sr_sr_next(
        const struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_END_OF_SEQUENCE if there is no previous
 * entry.
 */
int butterflyfish_map_sr_sr_prev(
        const struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Remove entry.
 * @param [in] object map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 */
int butterflyfish_map_sr_sr_remove_entry(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_map_entry_sr_sr *entry);

/**
 * @brief Remove all entries.
 * @param [in] object map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 */
int butterflyfish_map_sr_sr_remove_all_entries(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr_sr *other);

/**
 * @brief Associate value with key, if key is not already present.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_ALREADY_EXISTS if key is already
 * present in the map.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to associate value with key.
 */
int butterflyfish_map_sr_sr_add(
        struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        struct triggerfish_strong *value);

/**
 * @brief Associate value with key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 */
int butterflyfish_map_sr_sr_put(
        struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        struct triggerfish_strong *value);

/**
 * @brief Replace value for existing key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND if key is not present in
 * the map.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 */
int butterflyfish_map_sr_sr_replace(
        struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        struct triggerfish_strong *value);

/**
 * @brief Remove key-value association.
 * @param [in] object map instance.
 * @param [in] key of key-value association to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND if key is not present in
 * the map.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_sr_sr_remove(
        struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key);

/**
 * @brief Add all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be added, ignoring duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 */
int butterflyfish_map_sr_sr_add_all(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr_sr *other);

/**
 * @brief Set all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 */
int butterflyfish_map_sr_sr_put_all(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr_sr *other);

/**
 * @brief Replace all existing key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 */
int butterflyfish_map_sr_sr_replace_all(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr_sr *other);

/**
 * @brief Remove all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will remove matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_sr_sr_remove_all(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Retain all the entries that have matching keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will retain matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_sr_sr_retain_all(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr *other);

/**
 * @brief Add entries into map, perform action on duplicate key.
 * @param [in] object map instance.
 * @param [in] other stream of entries that will be merged into map.
 * @param [in] function to resolve duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_FUNCTION_IS_NULL if function is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add key-value association.
 * @note <b>function</b>'s error will be returned if present.
 */
int butterflyfish_map_sr_sr_merge(
        struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr_sr *other,
        int (*function)(
                const struct triggerfish_strong *,
                const struct triggerfish_strong *,
                struct triggerfish_strong **));

/**
 * @brief Check if key is present.
 * @param [in] object map instance.
 * @param [in] key whose presence is being checked.
 * @param [out] out receive true if present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_sr_sr_contains_key(
        const struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        bool *out);

/**
 * @brief Check if all keys are present.
 * @param [in] object map instance.
 * @param [in] other stream of keys to be checked for presence.
 * @param [out] out receive true if all are present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup keys.
 */
int butterflyfish_map_sr_sr_contains_all_keys(
        const struct butterflyfish_map_sr_sr *object,
        const struct butterflyfish_stream_sr *other,
        bool *out);

/**
 * @brief Retrieve value for key.
 * @param [in] object map instance.
 * @param [in] key for value.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup value for key.
 */
int butterflyfish_map_sr_sr_get(
        const struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        struct triggerfish_strong **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key for entry.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_sr_sr_get_entry(
        const struct butterflyfish_map_sr_sr *object,
        struct triggerfish_strong *key,
        struct butterflyfish_map_entry_sr_sr **out);

/**
 * @brief Set view of map keys.
 * @param [in] object map instance.
 * @param [out] out receive set view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_sr_sr_keys(
        struct butterflyfish_map_sr_sr *object,
        struct butterflyfish_set_sr **out);

/**
 * @brief Reducible list view of map values.
 * @param [in] object map instance.
 * @param [out] out receive reducible list view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_SR_SR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_sr_sr_values(
        struct butterflyfish_map_sr_sr *object,
        struct butterflyfish_reducible_list_sr **out);

#endif /* _BUTTERFLYFISH_MAP_SR_SR_H_ */
