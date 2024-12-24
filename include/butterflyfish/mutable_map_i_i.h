#ifndef _BUTTERFLYFISH_MUTABLE_MAP_I_I_H_
#define _BUTTERFLYFISH_MUTABLE_MAP_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "map_i_i_entry.h"
#include "settable_incremental_map_i_i.h"
#include "settable_reducible_map_i_i.h"

struct butterflyfish_mutable_set_i;
struct butterflyfish_ordered_settable_reducible_list_i;

#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_ENTRY_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_MAP_I_I_ERROR_KEY_ALREADY_EXISTS

struct butterflyfish_mutable_map_i_i {
    const struct butterflyfish_stream_i_i *const as_stream;
    const struct butterflyfish_collection_i_i *const as_collection;
    const struct butterflyfish_set_i_i *const as_set;
    const struct butterflyfish_settable_i_i *const as_settable;
    const struct butterflyfish_map_i_i *const as_map;
    const struct butterflyfish_addable_i_i *const as_addable;
    const struct butterflyfish_removable_i_i *const as_removable;
    const struct butterflyfish_settable_map_i_i *const as_settable_map;
    const struct butterflyfish_incremental_map_i_i *const as_incremental_map;
    const struct butterflyfish_reducible_map_i_i *const as_reducible_map;
    const struct butterflyfish_settable_incremental_map_i_i *const
            as_settable_incremental_map;
    const struct butterflyfish_settable_reducible_map_i_i *const
            as_settable_reducible_map;

    const struct butterflyfish_mutable_set_i *const keys;
    const struct butterflyfish_ordered_settable_reducible_list_i *const values;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the map.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY if map is empty.
     */
    int (*const first)(const void *object,
                       const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Last item of the map.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MAP_IS_EMPTY if map is
     * empty.
     */
    int (*const last)(const void *object,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE if there
     * is no next item.
     */
    int (*const next)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_END_OF_SEQUENCE if there
     * is no previous item.
     */
    int (*const prev)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Check if map contains the given key.
     * @param [in] object instance.
     * @param [in] key to check if key is present.
     * @param [out] out receive true if key is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the entry.
     */
    int (*const contains_key)(const void *object,
                              const struct sea_turtle_integer *key,
                              bool *out);

    /**
     * @brief Check if map contains the given value.
     * @param [in] object instance.
     * @param [in] value to check if value is present.
     * @param [out] out receive true if value is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the entry.
     */
    int (*const contains_value)(const void *object,
                                const struct sea_turtle_integer *value,
                                bool *out);

    /**
     * @brief Retrieve associated value for key.
     * @param [in] object instance.
     * @param [in] key to find.
     * @param [out] out receive the associated value.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is
     * not in the map instance.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the value.
     */
    int (*const get)(const void *object,
                     const struct sea_turtle_integer *key,
                     const struct sea_turtle_integer **value);

    /**
     * @brief Retrieve entry for key.
     * @param [in] object instance.
     * @param [in] key to find.
     * @param [out] out receive the entry.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is
     * not in the map instance.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the value.
     */
    int (*const get_entry)(const void *object,
                           const struct sea_turtle_integer *key,
                           const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Set value for key.
     * @param [in] object instance.
     * @param [in] key whose associated value will be set.
     * @param [in] value for value.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is
     * not in the map instance.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID if value
     * is invalid.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to set the value.
     * @note <b>value</b> is copied and then the associated value is set to it.
     */
    int (*const set)(void *object,
                     const struct sea_turtle_integer *key,
                     const struct sea_turtle_integer *value);

    /**
     * @brief Replace key.
     * @param [in] object instance.
     * @param [in] key whose value to be set.
     * @param [in] value of the key.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is
     * not in the map instance.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key
     * is already present in the map.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to set the key.
     * @note <b>value</b> is copied and then the key is set to it.
     */
    int (*const set_key)(void *object,
                         const struct sea_turtle_integer *key,
                         const struct sea_turtle_integer *value);

    /**
     * @brief Replace entry.
     * @param [in] object instance.
     * @param [in] entry to be changed.
     * @param [in] value to set entry to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_ENTRY_IS_NULL if entry is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key
     * is already present in the map.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID if value
     * is invalid.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to set the entry.
     * @note <b>value</b> is copied and then entry is set to it.
     */
    int (*const set_entry)(void *object,
                           const struct butterflyfish_map_i_i_entry *entry,
                           const struct butterflyfish_map_i_i_entry *value);

    /**
     * @brief Add value for key.
     * @param [in] object instance.
     * @param [in] key used for finding the associated value.
     * @param [in] value to add.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_ALREADY_EXISTS if key
     * is already present in the map.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_VALUE_IS_INVALID if value
     * is invalid.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value to the set.
     * @note <b>key</b> and <b>value</b> are copied.
     */
    int (*const add)(void *object,
                     const struct sea_turtle_integer *key,
                     const struct sea_turtle_integer *value);

    /**
     * @brief Remove key.
     * @param [in] object instance.
     * @param [in] key to be removed.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_OBJECT_IS_NULL if object
     * is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_IS_NULL if key is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_KEY_NOT_FOUND if key is
     * not in the map instance.
     * @throws BUTTERFLYFISH_MUTABLE_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the entry.
     */
    int (*const remove)(void *object,
                        const struct sea_turtle_integer *key);
};

#endif /* _BUTTERFLYFISH_MUTABLE_MAP_I_I_H_ */
