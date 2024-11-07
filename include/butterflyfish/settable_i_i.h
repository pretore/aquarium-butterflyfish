#ifndef _BUTTERFLYFISH_SETTABLE_I_I_H_
#define _BUTTERFLYFISH_SETTABLE_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sea-urchin.h>

#include "collection_i_i.h"

#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_SETTABLE_IS_EMPTY \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS \
    SEA_URCHIN_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SETTABLE_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED

struct butterflyfish_settable_i_i {
    int (*const as_collection)(
            const struct butterflyfish_settable_i_i *object,
            const struct butterflyfish_collection_i_i **out);

    int (*const set_item)(struct butterflyfish_settable_i_i *object,
                          const struct butterflyfish_map_i_i_entry *item,
                          const struct butterflyfish_map_i_i_entry *value);
};

/**
 * @brief Return settable as a stream.
 * @param [in] object settable instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_settable_i_i_as_stream(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_stream_i_i **out);

/**
 * @brief Return settable as a collection.
 * @param [in] object settable instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_settable_i_i_as_collection(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_collection_i_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_settable_i_i_count(
        const struct butterflyfish_settable_i_i *object,
        uintmax_t *out);

/**
 * @brief First item of the settable.
 * @param [in] object settable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_SETTABLE_IS_EMPTY if settable
 * is empty.
 */
int butterflyfish_settable_i_i_first(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Last item of the settable.
 * @param [in] object settable instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_SETTABLE_IS_EMPTY if settable
 * is empty.
 */
int butterflyfish_settable_i_i_last(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve next item.
 * @param [in] object settable instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_END_OF_SEQUENCE if there is no
 * next item.
 */
int butterflyfish_settable_i_i_next(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object settable instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_settable_i_i_prev(
        const struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry **out);

/**
 * @brief Set value for item.
 * @param [in] object settable instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_NULL if value is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_IS_INVALID if value is
 * invalid.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_VALUE_ALREADY_EXISTS if value is
 * already present.
 * @throws BUTTERFLYFISH_SETTABLE_I_I_ERROR_MEMORY_ALLOCATION_FAILED if there
 * is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_settable_i_i_set_item(
        struct butterflyfish_settable_i_i *object,
        const struct butterflyfish_map_i_i_entry *item,
        const struct butterflyfish_map_i_i_entry *value);

#endif /* _BUTTERFLYFISH_SETTABLE_I_I_H_ */
