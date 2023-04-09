#ifndef _BUTTERFLYFISH_MAP_S_S_H_
#define _BUTTERFLYFISH_MAP_S_S_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "collection_s_s.h"

struct sea_turtle_string;
struct butterflyfish_stream_s;
struct butterflyfish_set_s;
struct butterflyfish_reducible_list_s;

#define BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_S_S_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_S_S_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_S_S_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_MAP_S_S_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_COLLECTION_S_S_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_S_S_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL \
    SEA_URCHIN_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MAP_S_S_ERROR_KEY_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MAP_S_S_ERROR_KEY_NOT_FOUND \
    SEA_URCHIN_ERROR_VALUE_NOT_FOUND
#define BUTTERFLYFISH_MAP_S_S_ERROR_FUNCTION_IS_NULL \
    SEA_URCHIN_ERROR_FUNCTION_IS_NULL

struct butterflyfish_map_s_s {
    const struct butterflyfish_collection_s_s collection_s_s;

    int (*const add)(void *object,
                     const struct sea_turtle_string *key,
                     const struct sea_turtle_string *value);

    int (*const put)(void *object,
                     const struct sea_turtle_string *key,
                     const struct sea_turtle_string *value);

    int (*const replace)(void *object,
                         const struct sea_turtle_string *key,
                         const struct sea_turtle_string *value);

    int (*const remove)(void *object,
                        const struct sea_turtle_string *key);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_s_s *other);

    int (*const put_all)(void *object,
                         const struct butterflyfish_stream_s_s *other);

    int (*const replace_all)(void *object,
                             const struct butterflyfish_stream_s_s *other);

    int (*const remove_all)(void *object,
                            const struct butterflyfish_stream_s *other);

    int (*const retain_all)(void *object,
                            const struct butterflyfish_stream_s *other);

    int (*const merge)(void *object,
                       const struct butterflyfish_stream_s_s *other,
                       int (*function)(
                               const struct sea_turtle_string *,
                               const struct sea_turtle_string *,
                               struct sea_turtle_string **));

    int (*const remove_entry)(void *object,
                              const struct butterflyfish_map_entry_s_s *entry);

    int (*const remove_all_entries)(void *object,
                                    const struct butterflyfish_stream_s_s *other);

    int (*const contains_key)(const void *object,
                              const struct sea_turtle_string *key,
                              bool *out);

    int (*const contains_all_keys)(const void *object,
                                   const struct butterflyfish_stream_s *other,
                                   bool *out);

    int (*const get)(const void *object,
                     const struct sea_turtle_string *key,
                     const struct sea_turtle_string **out);

    int (*const get_entry)(const void *object,
                           const struct sea_turtle_string *key,
                           const struct butterflyfish_map_entry_s_s **out);

    int (*const keys)(void *object,
                      struct butterflyfish_set_s **out);

    int (*const values)(void *object,
                        struct butterflyfish_reducible_list_s **out);
};

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_s_s_count(
        const struct butterflyfish_map_s_s *object,
        uintmax_t *out);

/**
 * @brief First entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_s_s_first(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Last entry of the map.
 * @param [in] object map instance.
 * @param [out] out receive the entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MAP_IS_EMPTY if map is empty.
 */
int butterflyfish_map_s_s_last(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Retrieve next entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the next entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_END_OF_SEQUENCE if there is no next
 * entry.
 */
int butterflyfish_map_s_s_next(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        const struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Retrieve the previous entry.
 * @param [in] object map instance.
 * @param [in] entry current entry.
 * @param [out] out receive the previous entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_END_OF_SEQUENCE if there is no previous
 * entry.
 */
int butterflyfish_map_s_s_prev(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry,
        const struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Remove entry.
 * @param [in] object map instance.
 * @param [in] entry to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_ENTRY_IS_NULL if entry is <i>NULL</i>.
 */
int butterflyfish_map_s_s_remove_entry(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_map_entry_s_s *entry);

/**
 * @brief Remove all entries.
 * @param [in] object map instance.
 * @param [in] other stream of entries which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 */
int butterflyfish_map_s_s_remove_all_entries(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s_s *other);

/**
 * @brief Associate value with key, if key is not already present.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_ALREADY_EXISTS if key is already
 * present in the map.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to associate value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_map_s_s_add(
        struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        const struct sea_turtle_string *value);

/**
 * @brief Associate value with key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_map_s_s_put(
        struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        const struct sea_turtle_string *value);

/**
 * @brief Replace value for existing key.
 * @param [in] object map instance.
 * @param [in] key to which the value will be associated with.
 * @param [in] value that will returned from a lookup of key.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_NOT_FOUND if key is not present in
 * the map.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_map_s_s_replace(
        struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        const struct sea_turtle_string *value);

/**
 * @brief Remove key-value association.
 * @param [in] object map instance.
 * @param [in] key of key-value association to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_s_s_remove(
        struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key);

/**
 * @brief Add all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be added, ignoring duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b> and <b>value</b> are copied and then placed into the map.
 */
int butterflyfish_map_s_s_add_all(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s_s *other);

/**
 * @brief Set all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to association value with key.
 * @note <b>key</b>, if not already present, and <b>value</b> are copied and
 * then placed into the map.
 */
int butterflyfish_map_s_s_put_all(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s_s *other);

/**
 * @brief Replace all existing key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will be associated with keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to replace value for key.
 * @note <b>value</b> is copied and then placed into the map.
 */
int butterflyfish_map_s_s_replace_all(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s_s *other);

/**
 * @brief Remove all key-value associations.
 * @param [in] object map instance.
 * @param [in] other stream whose values will remove matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_s_s_remove_all(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Retain all the entries that have matching keys.
 * @param [in] object map instance.
 * @param [in] other stream whose values will retain matching keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_s_s_retain_all(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s *other);

/**
 * @brief Add entries into map, perform action on duplicate key.
 * @param [in] object map instance.
 * @param [in] other stream of entries that will be merged into map.
 * @param [in] function to resolve duplicate keys.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_FUNCTION_IS_NULL if function is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add key-value association.
 * @note <b>function</b>'s error will be returned if present.
 */
int butterflyfish_map_s_s_merge(
        struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s_s *other,
        int (*function)(
                const struct sea_turtle_string *,
                const struct sea_turtle_string *,
                struct sea_turtle_string **));

/**
 * @brief Check if key is present.
 * @param [in] object map instance.
 * @param [in] key whose presence is being checked.
 * @param [out] out receive true if present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_s_s_contains_key(
        const struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        bool *out);

/**
 * @brief Check if all keys are present.
 * @param [in] object map instance.
 * @param [in] other stream of keys to be checked for presence.
 * @param [out] out receive true if all are present, false otherwise.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup keys.
 */
int butterflyfish_map_s_s_contains_all_keys(
        const struct butterflyfish_map_s_s *object,
        const struct butterflyfish_stream_s *other,
        bool *out);

/**
 * @brief Retrieve value for key.
 * @param [in] object map instance.
 * @param [in] key for value.
 * @param [out] out receive value.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup value for key.
 */
int butterflyfish_map_s_s_get(
        const struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        const struct sea_turtle_string **out);

/**
 * @brief Retrieve entry for key.
 * @param [in] object map instance.
 * @param [in] key for entry.
 * @param [out] out receive entry.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_IS_NULL if key is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_KEY_NOT_FOUND if key not found in map.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to lookup key.
 */
int butterflyfish_map_s_s_get_entry(
        const struct butterflyfish_map_s_s *object,
        const struct sea_turtle_string *key,
        const struct butterflyfish_map_entry_s_s **out);

/**
 * @brief Set view of map keys.
 * @param [in] object map instance.
 * @param [out] out receive set view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_s_s_keys(
        struct butterflyfish_map_s_s *object,
        struct butterflyfish_set_s **out);

/**
 * @brief Reducible list view of map values.
 * @param [in] object map instance.
 * @param [out] out receive reducible list view.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_MAP_S_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_map_s_s_values(
        struct butterflyfish_map_s_s *object,
        struct butterflyfish_reducible_list_s **out);

#endif /* _BUTTERFLYFISH_MAP_S_S_H_ */
