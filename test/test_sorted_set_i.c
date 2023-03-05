#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_set_i_first(
                    (const struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_as_ordered_set_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_i_first(
                    (const struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_as_set_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_i_first(
                    (const struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_first(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
}

static void
check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_i_first(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_set_i_last(
                    (const struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_as_ordered_set_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_i_last(
                    (const struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY);
}

static void check_as_set_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_i_last(
                    (const struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_I_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_last(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct sea_turtle_integer *const item,
                         const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_set_i_next(
                    (const struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_set_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_i_next(
                    (const struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_i_next(
                    (const struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_next(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.stream_i.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_i_next(
                    (const struct butterflyfish_stream_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_set_i_prev(
                    (const struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_set_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_i_prev(
                    (const struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_i_prev(
                    (const struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.collection_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_prev(
                    (const struct butterflyfish_collection_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_ERROR_END_OF_SEQUENCE);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_add(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_add((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static int ar_emit_error(void *const object,
                         const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_set_i_add(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void
check_as_ordered_set_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_set_i_add(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_as_set_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_set_i_add(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_add(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_add(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_add(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL);
}

static int
ar_all_emit_error(void *const object,
                  const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_add_all(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_add_all(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_add_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_remove(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void
check_as_ordered_set_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_i_remove(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_as_set_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_i_remove(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_remove(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_remove(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_remove(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_remove_all(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_remove_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_remove_all(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_remove_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static int contains_emit_error(const void *const object,
                               const struct sea_turtle_integer *const value,
                               bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static int
contains_all_emit_error(const void *const object,
                        const struct butterflyfish_stream_i *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_contains_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_contains_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OTHER_IS_NULL);
}

static int
retain_all_emit_error(void *const object,
                      const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_retain_all(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_retain_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_retain_all(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_retain_all(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const struct sea_turtle_integer *const value,
                          const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_get(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_as_ordered_set_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_i_get(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_as_set_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_i_get(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_set_i_get(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_set_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_i_get(
                    (struct butterflyfish_ordered_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ordered_set_i.set_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_i_get(
                    (struct butterflyfish_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_ceiling(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_ceiling( (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_ceiling( (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_ceiling(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_ceiling(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_floor(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_floor( (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_floor( (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_floor(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_floor(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_higher(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_higher( (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_higher( (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_higher(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_higher(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_lower(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_lower( (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_VALUE_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_set_i_lower( (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_item_not_found(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_lower(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_set_i sorted_set_i = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_set_i *sorted_set_i;
    };
    struct object instance = {
            .sorted_set_i = &sorted_set_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_set_i_lower(
                    (struct butterflyfish_sorted_set_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_SET_I_ERROR_ITEM_NOT_FOUND);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_ordered_set_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_set_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_set_is_empty),
            cmocka_unit_test(check_as_ordered_set_last_error_on_set_is_empty),
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
            cmocka_unit_test(check_as_ordered_set_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_set_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_ordered_set_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_set_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_value_already_exits),
            cmocka_unit_test(check_as_ordered_set_add_error_on_value_already_exits),
            cmocka_unit_test(check_as_set_add_error_on_value_already_exits),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_as_ordered_set_remove_error_on_value_not_found),
            cmocka_unit_test(check_as_set_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_value_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_value_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_item_not_found),
            cmocka_unit_test(check_as_ordered_set_get_error_on_item_not_found),
            cmocka_unit_test(check_as_set_get_error_on_item_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_set_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_set_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_value_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_item_not_found),
            cmocka_unit_test(check_ceiling_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_value_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_item_not_found),
            cmocka_unit_test(check_floor_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_value_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_item_not_found),
            cmocka_unit_test(check_higher_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_value_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_item_not_found),
            cmocka_unit_test(check_lower_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
