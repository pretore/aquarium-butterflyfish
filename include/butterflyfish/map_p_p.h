#ifndef _BUTTERFLYFISH_MAP_P_P_H_
#define _BUTTERFLYFISH_MAP_P_P_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_p_p.h"

struct butterflyfish_stream_p;
struct butterflyfish_set_p;
struct butterflyfish_reducible_list_p;

#define BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_P_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_P_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MAP_P_P_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_P_P_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_COLLECTION_P_P_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_MAP_P_P_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_P_P_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_MAP_P_P_ERROR_KEY_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_P_P_ERROR_FUNCTION_IS_NULL \
    SEA_URCHIN_ERROR_FUNCTION_IS_NULL

struct butterflyfish_map_p_p {
    const struct butterflyfish_collection_p_p collection_p_p;

    int (*const add)(void *object,
                     const void *key,
                     const void *value);

    int (*const put)(void *object,
                     const void *key,
                     const void *value);

    int (*const replace)(void *object,
                         const void *key,
                         const void *value);

    int (*const remove)(void *object,
                        const void *key);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_p_p *other);

    int (*const put_all)(void *object,
                         const struct butterflyfish_stream_p_p *other);

    int (*const replace_all)(void *object,
                             const struct butterflyfish_stream_p_p *other);

    int (*const remove_all)(void *object,
                            const struct butterflyfish_stream_p *other);

    int (*const retain_all)(void *object,
                            const struct butterflyfish_stream_p *other);

    int (*const merge)(void *object,
                       const struct butterflyfish_stream_p_p *other,
                       int (*function)(
                               const void *,
                               const void *,
                               void **));

    int (*const remove_entry)(void *object,
                              const struct butterflyfish_map_entry_p_p *entry);

    int (*const remove_all_entries)(void *object,
                                    const struct butterflyfish_stream_p_p *other);

    int (*const contains_key)(const void *object,
                              const void *key,
                              bool *out);

    int (*const contains_all_keys)(const void *object,
                                   const struct butterflyfish_stream_p *other,
                                   bool *out);

    int (*const get)(const void *object,
                     const void *key,
                     const void **out);

    int (*const get_entry)(const void *object,
                           const void *key,
                           const struct butterflyfish_map_entry_p_p **out);

    int (*const keys)(void *object,
                      struct butterflyfish_set_p **out);

    int (*const values)(void *object,
                        struct butterflyfish_reducible_list_p **out);
};

/**
 * @brief Return map as a stream.
 * @param [in] object map instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_p_p_as_stream(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p **out);

/**
 * @brief Return map as a collection.
 * @param [in] object map instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_p_p_as_collection(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_collection_p_p **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_p_p_count(
        const struct butterflyfish_map_p_p *object,
        uintmax_t *out);

/**
 * @brief First entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_p_p_first(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Last entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_p_p_last(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_END_OF_SEQUENCE if there is no next
 * entry.
 */
int butterflyfish_map_p_p_next(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry,
        const struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_END_OF_SEQUENCE if there is no previous
 * entry.
 */
int butterflyfish_map_p_p_prev(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry,
        const struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Remove entry.
 * @param [in] object map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 */
int butterflyfish_map_p_p_remove_entry(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_map_entry_p_p *entry);

/**
 * @brief Remove all entries.
 * @param [in] object map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 */
int butterflyfish_map_p_p_remove_all_entries(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p *other);

/**
 * @brief Associate value with key, if key is not already present.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_KEY_ALREADY_EXISTS if key is already
 * present in the map.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to associate value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_map_p_p_add(
        struct butterflyfish_map_p_p *object,
        const void *key,
        const void *value);

/**
 * @brief Associate value with key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_map_p_p_put(
        struct butterflyfish_map_p_p *object,
        const void *key,
        const void *value);

/**
 * @brief Replace value for existing key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND if key is not present in
 * the map.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_map_p_p_replace(
        struct butterflyfish_map_p_p *object,
        const void *key,
        const void *value);

/**
 * @brief Remove key-value association.
 * @param [in] object map instance.
 * @param [in] key of key-value association to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND if key is not present in
 * the map.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_p_p_remove(
        struct butterflyfish_map_p_p *object,
        const void *key);

/**
 * @brief Add all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be added, ignoring duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_map_p_p_add_all(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p *other);

/**
 * @brief Set all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_map_p_p_put_all(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p *other);

/**
 * @brief Replace all existing key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_map_p_p_replace_all(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p *other);

/**
 * @brief Remove all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will remove matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_p_p_remove_all(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Retain all the entries that have matching keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will retain matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_p_p_retain_all(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p *other);

/**
 * @brief Add entries into map, perform action on duplicate key.
 * @param [in] object map instance.
 * @param [in] other stream of entries that will be merged into map.
 * @param [in] function to resolve duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_FUNCTION_IS_NULL if function is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add key-value association.
 * @note <b>function</b>'s error will be returned if present.
 */
int butterflyfish_map_p_p_merge(
        struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p_p *other,
        int (*function)(
                const void *,
                const void *,
                void **));

/**
 * @brief Check if key is present.
 * @param [in] object map instance.
 * @param [in] key whose presence is being checked.
 * @param [out] out receive true if present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_p_p_contains_key(
        const struct butterflyfish_map_p_p *object,
        const void *key,
        bool *out);

/**
 * @brief Check if all keys are present.
 * @param [in] object map instance.
 * @param [in] other stream of keys to be checked for presence.
 * @param [out] out receive true if all are present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup keys.
 */
int butterflyfish_map_p_p_contains_all_keys(
        const struct butterflyfish_map_p_p *object,
        const struct butterflyfish_stream_p *other,
        bool *out);

/**
 * @brief Retrieve value for key.
 * @param [in] object map instance.
 * @param [in] key for value.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup value for key.
 */
int butterflyfish_map_p_p_get(
        const struct butterflyfish_map_p_p *object,
        const void *key,
        const void **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key for entry.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_p_p_get_entry(
        const struct butterflyfish_map_p_p *object,
        const void *key,
        const struct butterflyfish_map_entry_p_p **out);

/**
 * @brief Set view of map keys.
 * @param [in] object map instance.
 * @param [out] out receive set view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_p_p_keys(
        struct butterflyfish_map_p_p *object,
        struct butterflyfish_set_p **out);

/**
 * @brief Reducible list view of map values.
 * @param [in] object map instance.
 * @param [out] out receive reducible list view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_P_P_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_p_p_values(
        struct butterflyfish_map_p_p *object,
        struct butterflyfish_reducible_list_p **out);

#endif /* _BUTTERFLYFISH_MAP_P_P_H_ */
