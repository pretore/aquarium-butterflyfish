#ifndef _BUTTERFLYFISH_QUEUE_S_H_
#define _BUTTERFLYFISH_QUEUE_S_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "reducible_queue_s.h"

struct sea_turtle_string;

#define BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OBJECT_IS_NULL
#define BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_OUT_IS_NULL
#define BUTTERFLYFISH_QUEUE_S_ERROR_QUEUE_IS_EMPTY \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_QUEUE_IS_EMPTY
#define BUTTERFLYFISH_QUEUE_S_ERROR_ITEM_IS_NULL \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_ITEM_IS_NULL
#define BUTTERFLYFISH_QUEUE_S_ERROR_END_OF_SEQUENCE \
    BUTTERFLYFISH_REDUCIBLE_QUEUE_S_ERROR_END_OF_SEQUENCE
#define BUTTERFLYFISH_QUEUE_S_ERROR_VALUE_IS_NULL \
    SEA_URCHIN_ERROR_VALUE_IS_NULL
#define BUTTERFLYFISH_QUEUE_S_ERROR_OTHER_IS_NULL \
    SEA_URCHIN_ERROR_OTHER_IS_NULL
#define BUTTERFLYFISH_QUEUE_S_ERROR_MEMORY_ALLOCATION_FAILED \
    SEA_URCHIN_ERROR_MEMORY_ALLOCATION_FAILED
#define BUTTERFLYFISH_QUEUE_S_ERROR_VALUE_IS_INVALID \
    SEA_URCHIN_ERROR_VALUE_IS_INVALID

struct butterflyfish_queue_s {
    const struct butterflyfish_reducible_queue_s reducible_queue_s;

    int (*const add)(void *object,
                     const struct sea_turtle_string *value);

    int (*const add_all)(void *object,
                         const struct butterflyfish_stream_s *other);
};

/**
 * @brief Return queue as a collection.
 * @param [in] object queue instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_s_as_stream(
        const struct butterflyfish_queue_s *object,
        const struct butterflyfish_stream_s **out);

/**
 * @brief Return queue as a collection.
 * @param [in] object queue instance.
 * @param [out] out receive collection.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_s_as_collection(
        const struct butterflyfish_queue_s *object,
        const struct butterflyfish_collection_s **out);

/**
 * @brief Return queue as a reducible queue.
 * @param [in] object queue instance.
 * @param [out] out receive reducible queue.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_s_as_reducible_queue(
        struct butterflyfish_queue_s *object,
        struct butterflyfish_reducible_queue_s **out);

/**
 * @brief Retrieve the count of items.
 * @param [in] object instance whose count we are to retrieve.
 * @param [out] out receive the count.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 */
int butterflyfish_queue_s_count(
        const struct butterflyfish_queue_s *object,
        uintmax_t *out);

/**
 * @brief First item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_s_first(
        const struct butterflyfish_queue_s *object,
        const struct sea_turtle_string **out);

/**
 * @brief Last item of the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_QUEUE_IS_EMPTY if queue is empty.
 */
int butterflyfish_queue_s_last(
        const struct butterflyfish_queue_s *object,
        const struct sea_turtle_string **out);

/**
 * @brief Retrieve next item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the next item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is
 * <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_END_OF_SEQUENCE if there is no next item.
 */
int butterflyfish_queue_s_next(
        const struct butterflyfish_queue_s *object,
        const struct sea_turtle_string *item,
        const struct sea_turtle_string **out);

/**
 * @brief Retrieve the previous item.
 * @param [in] object queue instance.
 * @param [in] item current item.
 * @param [out] out receive the previous item.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_ITEM_IS_NULL if item is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_END_OF_SEQUENCE if there is no
 * previous item.
 */
int butterflyfish_queue_s_prev(
        const struct butterflyfish_queue_s *object,
        const struct sea_turtle_string *item,
        const struct sea_turtle_string **out);

/**
 * @brief Remove value from the front the queue.
 * @param [in] object queue instance.
 * @param [out] out receive the value in the front of the queue.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OUT_IS_NULL if out is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_QUEUE_IS_EMPTY if queue is empty.
 * @note Invalidate received value once done using it.
 */
int butterflyfish_queue_s_remove(
        struct butterflyfish_queue_s *object,
        struct sea_turtle_string *out);

/**
 * @brief Add value to the end the queue.
 * @param [in] object queue instance.
 * @param [in] value to add to the end.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_VALUE_IS_NULL if value is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * insufficient memory to add value.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_VALUE_IS_INVALID if value is invalid.
 * @note <b>value</b> is copied and then appended to the queue.
 */
int butterflyfish_queue_s_add(
        struct butterflyfish_queue_s *object,
        const struct sea_turtle_string *value);

/**
 * @brief Add all the values to the end.
 * @param [in] object queue instance.
 * @param [in] other stream of values which are added, ignoring the invalid
 * values.
 * @return On success <i>0</i>, otherwise an error code.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OBJECT_IS_NULL if object is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_OTHER_IS_NULL if other is <i>NULL</i>.
 * @throws BUTTERFLYFISH_QUEUE_S_ERROR_MEMORY_ALLOCATION_FAILED if there is
 * not enough memory to add the values.
 * @note Each <b>value</b> is copied and then appended to the queue.
 */
int butterflyfish_queue_s_add_all(
        struct butterflyfish_queue_s *object,
        const struct butterflyfish_stream_s *other);

#endif /* _BUTTERFLYFISH_QUEUE_S_H_ */
