#ifndef _BUTTERFLYFISH_QUEUE_WR_H_
#define _BUTTERFLYFISH_QUEUE_WR_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "reducible_queue_wr.h"

struct triggerfish_weak;

#define BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_QUEUE_WR_ERROR_QUEUE_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_QUEUE_IS_EMPTY
#define BUTTERFLYFISH_QUEUE_WR_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_QUEUE_WR_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_WR_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_QUEUE_WR_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_QUEUE_WR_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_QUEUE_WR_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_QUEUE_WR_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_queue_wr {
    const struct butterflyfish_reducible_queue_wr reducible_queue_wr;

    int (*const add)(void *object,
                     const struct triggerfish_weak *value);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_wr *other);
};

/**
 * @brief Return queue as a collection.
 * @param [in] object queue instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_wr_as_stream(
        const struct butterflyfish_queue_wr *object,
        const struct butterflyfish_stream_wr **out);

/**
 * @brief Return queue as a collection.
 * @param [in] object queue instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_wr_as_collection(
        const struct butterflyfish_queue_wr *object,
        const struct butterflyfish_collection_wr **out);

/**
 * @brief Return queue as a reducible queue.
 * @param [in] object queue instance.
 * @param [out] out receive reducible queue.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_wr_as_reducible_queue(
        struct butterflyfish_queue_wr *object,
        struct butterflyfish_reducible_queue_wr **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_wr_count(
        const struct butterflyfish_queue_wr *object,
        uintmax_t *out);

/**
 * @brief First item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_wr_first(
        const struct butterflyfish_queue_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Last item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_wr_last(
        const struct butterflyfish_queue_wr *object,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve next item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_queue_wr_next(
        const struct butterflyfish_queue_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_queue_wr_prev(
        const struct butterflyfish_queue_wr *object,
        const struct triggerfish_weak *item,
        const struct triggerfish_weak **out);

/**
 * @brief Remove value from the front the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the value in the front of the queue.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_wr_remove(
        struct butterflyfish_queue_wr *object,
        struct triggerfish_weak **out);

/**
 * @brief Add value to the end the queue.
 * @param [in] object queue instance.
 * @param [in] value to add to the end.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_VALUE_IS_INVALID if value is invalid.
 * @note <b>value</b> is copied and then appended to the queue.
 */
int butterflyfish_queue_wr_add(
        struct butterflyfish_queue_wr *object,
        const struct triggerfish_weak *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object queue instance.
 * @param [in] other stream of values which are added, ignoring the invalid
 * values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_WR_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and then appended to the queue.
 */
int butterflyfish_queue_wr_add_all(
        struct butterflyfish_queue_wr *object,
        const struct butterflyfish_stream_wr *other);

#endif /* _BUTTERFLYFISH_QUEUE_WR_H_ */
