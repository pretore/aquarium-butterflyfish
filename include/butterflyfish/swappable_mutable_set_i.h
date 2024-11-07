#ifndef _BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_H_
#define _BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "swappable_settable_incremental_set_i.h"
#include "swappable_settable_reducible_set_i.h"
#include "ordered_mutable_set_i.h"

struct sea_turtle_integer;

#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_SET_IS_EMPTY \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_SET_IS_EMPTY
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND \
    BUTTERFLYFISH_ORDERED_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND

struct butterflyfish_swappable_mutable_set_i {
    int (*const as_swappable_settable_incremental_set)(
            struct butterflyfish_swappable_mutable_set_i *object,
            struct butterflyfish_swappable_settable_incremental_set_i **out);

    int (*const as_swappable_settable_reducible_set)(
            struct butterflyfish_swappable_mutable_set_i *object,
            struct butterflyfish_swappable_settable_reducible_set_i **out);

    int (*const as_ordered_mutable_set)(
            struct butterflyfish_swappable_mutable_set_i *object,
            struct butterflyfish_ordered_mutable_set_i **out);
};

/**
 * @brief Return swappable mutable set as a stream.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive stream.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_stream(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i **out);

/**
 * @brief Return swappable mutable set as a collection.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_collection(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_collection_i **out);

/**
 * @brief Return swappable mutable set as addable.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive addable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_addable(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_addable_i **out);

/**
 * @brief Return swappable mutable set as removable.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive removable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_removable(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_removable_i **out);

/**
 * @brief Return swappable mutable set as settable.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive settable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_settable(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_settable_i **out);

/**
 * @brief Return swappable mutable set as ordered.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_ordered_i **out);

/**
 * @brief Return swappable mutable set as a swappable.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_i **out);

/**
 * @brief Return swappable mutable set as a set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_set(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_set_i **out);

/**
 * @brief Return swappable mutable set as a settable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_settable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_settable_set_i **out);

/**
 * @brief Return swappable mutable set as a incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as a reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as a settable incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive settable incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_settable_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_settable_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as a settable reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive settable reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_settable_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_settable_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as a mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive mutable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_mutable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_mutable_set_i **out);

/**
 * @brief Return swappable mutable set as an ordered set.
 * @param [in] object swappable ordered set instance.
 * @param [out] out receive ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_set(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_ordered_set_i **out);

/**
 * @brief Return swappable mutable set as an insertable.
 * @param [in] object swappable ordered set instance.
 * @param [out] out receive insertable.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_insertable(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_insertable_i **out);

/**
 * @brief Return swappable mutable set as an ordered settable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_settable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_settable_set_i **out);

/**
 * @brief Return swappable mutable set as an ordered settable incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered settable incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_settable_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_settable_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as an ordered settable reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered settable reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_settable_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_settable_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as an ordered incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as an ordered reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive ordered reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable settable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable settable set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_settable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_settable_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable settable incremental set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable settable incremental set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_settable_incremental_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_settable_incremental_set_i **out);

/**
 * @brief Return swappable mutable set as a swappable settable reducible set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive swappable settable reducible set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_swappable_settable_reducible_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_swappable_settable_reducible_set_i **out);

/**
 * @brief Return swappable mutable set as a mutable ordered set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive mutable ordered set.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_as_ordered_mutable_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        struct butterflyfish_ordered_mutable_set_i **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_count(
        const struct butterflyfish_swappable_mutable_set_i *object,
        uintmax_t *out);

/**
 * @brief First item of the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_swappable_mutable_set_i_first(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Last item of the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_SET_IS_EMPTY if set is
 * empty.
 */
int butterflyfish_swappable_mutable_set_i_last(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve next item.
 * @param [in] object swappable mutable set instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE if there
 * is no next item.
 */
int butterflyfish_swappable_mutable_set_i_next(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object swappable mutable set instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_END_OF_SEQUENCE if there
 * is no previous item.
 */
int butterflyfish_swappable_mutable_set_i_prev(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer **out);

/**
 * @brief Check if swappable mutable set contains the given value.
 * @param [in] object swappable mutable set instance.
 * @param [in] value to check if value is present.
 * @param [out] out receive true if value is present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_swappable_mutable_set_i_contains(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *value,
        bool *out);

/**
 * @brief Check if swappable mutable set contains all the given values.
 * @param [in] object swappable mutable set instance.
 * @param [in] other stream whose values will be checked for presence in set.
 * @param [out] out receive true if all values are present, otherwise false.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_swappable_mutable_set_i_contains_all(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i *other,
        bool *out);

/**
 * @brief Retrieve item for value.
 * @param [in] object swappable mutable set instance.
 * @param [in] value to find.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OUT_IS_NULL if out is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND if value
 * is not in the set instance.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_swappable_mutable_set_i_get(
        const struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *value,
        const struct sea_turtle_integer **out);

/**
 * @brief Set value for item.
 * @param [in] object swappable mutable set instance.
 * @param [in] item to set.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then item is set to it.
 */
int butterflyfish_swappable_mutable_set_i_set_item(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Set value for looked up item.
 * @param [in] object set instance.
 * @param [in] item to lookup.
 * @param [in] value to which item is to be set to.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND if
 * item is not in the set.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is not enough memory to set the item to value.
 * @note <b>value</b> is copied and then the lookup item is set to it.
 */
int butterflyfish_swappable_mutable_set_i_set(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Add value to the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied and then placed into the set.
 */
int butterflyfish_swappable_mutable_set_i_add(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *value);

/**
 * @brief Add all the values to the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the set.
 * @note streamed <b>values</b> are copied and then placed into the set.
 */
int butterflyfish_swappable_mutable_set_i_add_all(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Insert value into the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] item where value is to be inserted.
 * @param [in] value to be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_ALREADY_EXISTS if
 * value is already present in the set.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_INVALID if
 * value is invalid.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add value to the set.
 * @note <b>value</b> is copied and then placed into the set.
 */
int butterflyfish_swappable_mutable_set_i_insert(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *value);

/**
 * @brief Insert all the values into to the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] item where all the values are inserted.
 * @param [in] other stream whose values will be added.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to add streamed values to the set.
 * @note streamed <b>values</b> are copied and then placed into the set.
 */
int butterflyfish_swappable_mutable_set_i_insert_all(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Remove item.
 * @param [in] object swappable mutable set instance.
 * @param [in] item to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item
 * is <i>NULL</i>.
 * @note <b>item</b> is invalidated when removed.
 */
int butterflyfish_swappable_mutable_set_i_remove_item(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item);

/**
 * @brief Remove all items.
 * @param [in] object set instance.
 * @param [in] other stream of items which are to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @note streamed items within <b>other</b> is invalidated when removed.
 */
int butterflyfish_swappable_mutable_set_i_remove_all_items(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Remove value from the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] value to be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_IS_NULL if value
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_VALUE_NOT_FOUND if value
 * is not in the set instance.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the value.
 */
int butterflyfish_swappable_mutable_set_i_remove(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *value);

/**
 * @brief Remove values from the swappable mutable set.
 * @param [in] object swappable mutable set instance.
 * @param [in] other stream whose values will be removed.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the streamed values in the set.
 */
int butterflyfish_swappable_mutable_set_i_remove_all(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Retain all the values present in both.
 * @param [in] object swappable ordered set instance.
 * @param [in] other stream whose values, if present in set too, will be
 * retained.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if object
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_MEMORY_ALLOCATION_FAILED
 * if there is insufficient memory to find the item.
 */
int butterflyfish_swappable_mutable_set_i_retain_all(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct butterflyfish_stream_i *other);

/**
 * @brief Swap the two items.
 * @param [in] object set instance.
 * @param [in] item first item.
 * @param [in] other other item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OBJECT_IS_NULL if
 * object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_ITEM_IS_NULL if item is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_ERROR_OTHER_IS_NULL if other
 * is <i>NULL</i>.
 */
int butterflyfish_swappable_mutable_set_i_swap(
        struct butterflyfish_swappable_mutable_set_i *object,
        const struct sea_turtle_integer *item,
        const struct sea_turtle_integer *other);

#endif /* _BUTTERFLYFISH_SWAPPABLE_MUTABLE_SET_I_H_ */
