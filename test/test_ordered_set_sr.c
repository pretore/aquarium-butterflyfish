#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_sr_first(
                    (const struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
}

static void check_as_set_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_sr_first(
                    (const struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_first(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void
check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_sr_first(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_sr_last(
                    (const struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
}

static void check_as_set_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_sr_last(
                    (const struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_sr_last(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_COLLECTION_IS_EMPTY);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct triggerfish_strong *const item,
                         struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_sr_next(
                    (const struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_sr_next(
                    (const struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_next(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.stream_sr.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_sr_next(
                    (const struct butterflyfish_stream_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_SR_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_sr_prev(
                    (const struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_sr_prev(
                    (const struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.collection_sr.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_sr_prev(
                    (const struct butterflyfish_collection_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_SR_ERROR_END_OF_SEQUENCE);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_add(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_add((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL);
}

static int ar_emit_error(void *const object,
                         struct triggerfish_strong *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_set_sr_add(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_as_set_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_set_sr_add(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_add(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_add(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_add_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL);
}

static int
ar_all_emit_error(void *const object,
                  const struct butterflyfish_stream_sr *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_add_all(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_add_all(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND);
}

static void check_as_set_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_sr_remove(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_remove(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_remove_all(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_remove_all(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static int contains_emit_error(const void *const object,
                               struct triggerfish_strong *const value,
                               bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_contains(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_contains(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static int
contains_all_emit_error(const void *const object,
                        const struct butterflyfish_stream_sr *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_contains_all(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_contains_all(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OTHER_IS_NULL);
}

static int
retain_all_emit_error(void *const object,
                      const struct butterflyfish_stream_sr *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_retain_all(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_retain_all(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_sr_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const struct triggerfish_strong *const value,
                          struct triggerfish_strong **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_sr_get(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND);
}

static void check_as_set_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_sr_get(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_ITEM_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_sr_get(
                    (struct butterflyfish_ordered_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_sr ordered_set_sr = {
            .set_sr.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_sr *ordered_set_sr;
    };
    struct object instance = {
            .ordered_set_sr = &ordered_set_sr
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_sr_get(
                    (struct butterflyfish_set_sr *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_SR_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_set_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_set_is_empty),
            cmocka_unit_test(check_as_set_last_error_on_set_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_set_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_set_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_value_already_exits),
            cmocka_unit_test(check_as_set_add_error_on_value_already_exits),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_as_set_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_value_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_value_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_item_not_found),
            cmocka_unit_test(check_as_set_get_error_on_item_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_get_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
