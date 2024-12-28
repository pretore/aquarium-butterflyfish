#ifndef _BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_H_
#define _BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "map_$t$_entry.h"
#include "insertable_$t$.h"
#include "ordered_map_$t$.h"
#include "incremental_map_$t$.h"

struct butterflyfish_ordered_incremental_set_$mkt$;
struct butterflyfish_ordered_list_$mvt$;

#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MAP_IS_EMPTY
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_IS_NULL
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_MAP_$T$_ERROR_KEY_NOT_FOUND
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS \
    BUTTERFLYFISH_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS

struct butterflyfish_ordered_incremental_map_$t$ {
    const struct butterflyfish_stream_$t$ *const as_stream;
    const struct butterflyfish_collection_$t$ *const as_collection;
    const struct butterflyfish_set_$t$ *const as_set;
    const struct butterflyfish_map_$t$ *const as_map;
    const struct butterflyfish_ordered_$t$ *const as_ordered;
    const struct butterflyfish_addable_$t$ *const as_addable;
    const struct butterflyfish_insertable_$t$ *const as_insertable;
    const struct butterflyfish_ordered_map_$t$ *const as_ordered_map;
    const struct butterflyfish_incremental_map_$t$ *const as_incremental_map;

    const struct butterflyfish_ordered_incremental_set_$mkt$ *const keys;
    const struct butterflyfish_ordered_list_$mvt$ *values;

    /**
     * @brief Retrieve the count of items.
     * @param [in] object instance whose count we are to retrieve.
     * @param [out] out receive the count.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the map.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY
     * if map is empty.
     */
    int (*const first)(const void *object,
                       const $v$*out);

    /**
     * @brief Last item of the map.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MAP_IS_EMPTY
     * if map is empty.
     */
    int (*const last)(const void *object,
                      const $v$*out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE
     * if there is no next item.
     */
    int (*const next)(const void *object,
                      const $v$item,
                      const $v$*out);

    /**
     * @brief Retrieve the previous item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the previous item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_END_OF_SEQUENCE
     * if there is no previous item.
     */
    int (*const prev)(const void *object,
                      const $v$item,
                      const $v$*out);

    /**
     * @brief Check if map contains the given key.
     * @param [in] object instance.
     * @param [in] key to check if key is present.
     * @param [out] out receive true if key is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL
     * if key is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the entry.
     */
    int (*const contains_key)(const void *object,
                              const $mkv$key,
                              bool *out);

    /**
     * @brief Check if map contains the given value.
     * @param [in] object instance.
     * @param [in] value to check if value is present.
     * @param [out] out receive true if value is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the entry.
     */
    int (*const contains_value)(const void *object,
                                const $mvv$value,
                                bool *out);

    /**
     * @brief Retrieve associated value for key.
     * @param [in] object instance.
     * @param [in] key to find.
     * @param [out] out receive the associated value.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL
     * if key is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND
     * if key is not in the map instance.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the value.
     */
    int (*const get)(const void *object,
                     const $mkv$key,
                     const $mvv$*value);

    /**
     * @brief Retrieve entry for key.
     * @param [in] object instance.
     * @param [in] key to find.
     * @param [out] out receive the entry.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL
     * if key is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OUT_IS_NULL
     * if out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_NOT_FOUND
     * if key is not in the map instance.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the value.
     */
    int (*const get_entry)(const void *object,
                           const $mkv$key,
                           const $v$*out);

    /**
     * @brief Add value for key.
     * @param [in] object instance.
     * @param [in] key used for finding the associated value.
     * @param [in] value to add.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL
     * if key is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS
     * if key is already present in the map.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID
     * if value is invalid.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value to the set.
     * @note <b>key</b> and <b>value</b> are copied.
     */
    int (*const add)(void *object,
                     const $mkv$key,
                     const $mvv$value);

    /**
     * @brief Insert value for key at item.
     * @param [in] object instance.
     * @param [in] key used for finding the associated value.
     * @param [in] value to add.
     * @param [in] item where newly created entry is to be inserted.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_IS_NULL
     * if key is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_ITEM_IS_NULL
     * if item is <i>NULL</i>.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_KEY_ALREADY_EXISTS
     * if key is already present in the map.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_VALUE_IS_INVALID
     * if value is invalid.
     * @throws BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to add value to the insertable.
     * @note <b>key</b> and <b>value</b> are copied.
     */
    int (*const insert)(void *object,
                        const $mkv$key,
                        const $mvv$value,
                        const $v$item);

};

#endif /* _BUTTERFLYFISH_ORDERED_INCREMENTAL_MAP_$T$_H_ */
