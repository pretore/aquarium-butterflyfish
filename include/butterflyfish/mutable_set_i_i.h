#ifndef _BUTTERFLYFISH_MUTABLE_SET_I_I_H_
#define _BUTTERFLYFISH_MUTABLE_SET_I_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "settable_incremental_set_i_i.h"
#include "settable_reducible_set_i_i.h"

struct butterflyfish_map_i_i_entry;

#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_SETTABLE_INCREMENTAL_SET_I_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_mutable_set_i_i {
    const struct butterflyfish_stream_i_i *const as_stream;
    const struct butterflyfish_collection_i_i *const as_collection;
    const struct butterflyfish_set_i_i *const as_set;
    const struct butterflyfish_settable_i_i *const as_settable;
    const struct butterflyfish_addable_i_i *const as_addable;
    const struct butterflyfish_removable_i_i *const as_removable;
    const struct butterflyfish_settable_set_i_i *const as_settable_set;
    const struct butterflyfish_incremental_set_i_i *const as_incremental_set;
    const struct butterflyfish_reducible_set_i_i *const as_reducible_set;
    const struct butterflyfish_settable_incremental_set_i_i *const
            as_settable_incremental_set_i_i;
    const struct butterflyfish_settable_reducible_set_i_i *const
            as_settable_reducible_set_i_i;

    /**
      * @brief Retrieve the count of items.
      * @param [in] object instance whose count we are to retrieve.
      * @param [out] out receive the count.
      * @return On success <i>0</i>, otherwise an error code.
      * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
      * <i>NULL</i>.
      * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
      * <i>NULL</i>.
      */
    int (*const count)(const void *object, uintmax_t *out);

    /**
     * @brief First item of the collection.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_SET_IS_EMPTY if set is empty.
     */
    int (*const first)(const void *object,
                       const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Last item of the set.
     * @param [in] object instance.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_SET_IS_EMPTY if set is empty.
     */
    int (*const last)(const void *object,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Retrieve next item.
     * @param [in] object instance.
     * @param [in] item current item.
     * @param [out] out receive the next item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_END_OF_SEQUENCE if there is
     * no next item.
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
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_END_OF_SEQUENCE if there is
     * no previous item.
     */
    int (*const prev)(const void *object,
                      const struct butterflyfish_map_i_i_entry *item,
                      const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Check if set contains the given value.
     * @param [in] object instance.
     * @param [in] value to check if value is present.
     * @param [out] out receive true if value is present, otherwise false.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if out is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the item.
     */
    int (*const contains)(const void *object,
                          const struct butterflyfish_map_i_i_entry *value,
                          bool *out);

    /**
     * @brief Retrieve item for value.
     * @param [in] object instance.
     * @param [in] value to find.
     * @param [out] out receive the item.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL
     * if object is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL
     * if value is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OUT_IS_NULL if
     * out is <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND
     * if value is not in the set instance.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is insufficient memory to find the item.
     */
    int (*const get)(const void *object,
                     const struct butterflyfish_map_i_i_entry *value,
                     const struct butterflyfish_map_i_i_entry **out);

    /**
     * @brief Set value for item.
     * @param [in] object instance.
     * @param [in] item to set.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_INVALID if value is
     * invalid.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @note <b>value</b> is copied and then item is set to it.
     */
    int (*const set_item)(void *object,
                          const struct butterflyfish_map_i_i_entry *item,
                          const struct butterflyfish_map_i_i_entry *value);

    /**
     * @brief Set value for looked up item.
     * @param [in] object instance.
     * @param [in] item to lookup.
     * @param [in] value to which item is to be set to.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND if item is
     * not in the set.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present in the set.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_INVALID if value
     * invalid.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED
     * if there is not enough memory to set the item to value.
     * @note <b>value</b> is copied and then the lookup item is set to it.
     */
    int (*const set)(void *object,
                     const struct butterflyfish_map_i_i_entry *item,
                     const struct butterflyfish_map_i_i_entry *value);

    /**
     * @brief Add value.
     * @param [in] object instance.
     * @param [in] value to be added.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_ALREADY_EXISTS if
     * value is already present.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_INVALID if value is
     * invalid.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
     * there is insufficient memory to add value.
     * @note <b>value</b> is copied.
     */
    int (*const add)(void *object,
                     const struct butterflyfish_map_i_i_entry *value);

    /**
     * @brief Remove item.
     * @param [in] object instance.
     * @param [in] item to be removed.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_ITEM_IS_NULL if item is
     * <i>NULL</i>.
     * @note <b>item</b> is invalidated when removed.
     */
    int (*const remove_item)(void *object,
                             const struct butterflyfish_map_i_i_entry *item);

    /**
     * @brief Remove value.
     * @param [in] object instance.
     * @param [in] value to be removed.
     * @return On success <i>0</i>, otherwise an error code.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_OBJECT_IS_NULL if object is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_IS_NULL if value is
     * <i>NULL</i>.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_VALUE_NOT_FOUND if value is
     * not in the set instance.
     * @throws BUTTERFLYFISH_MUTABLE_SET_I_I_ERROR_MEMORY_ALLOCATION_FAILED if
     * there is insufficient memory to find the value.
     */
    int (*const remove)(void *object,
                        const struct butterflyfish_map_i_i_entry *value);

};

#endif /* _BUTTERFLYFISH_MUTABLE_SET_I_I_H_ */
