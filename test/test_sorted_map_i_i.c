#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              const struct butterflyfish_map_entry_i_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_sorted_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_first(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_first(
                    (const struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_i_i_first(
                    (const struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_i_first(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_i_i_first(
                    (const struct butterflyfish_stream_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_sorted_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_last(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_last(
                    (const struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_i_i_last(
                    (const struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_i_i_last(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_i_i *const entry,
              const struct butterflyfish_map_entry_i_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_sorted_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_next(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_next(
                    (const struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_i_i_next(
                    (const struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_i_next(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.stream_i_i.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_i_i_next(
                    (const struct butterflyfish_stream_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_sorted_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_prev(
                    (const struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_prev(
                    (const struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_i_i_prev(
                    (const struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.collection_i_i.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_i_i_prev(
                    (const struct butterflyfish_collection_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_I_I_ERROR_END_OF_SEQUENCE);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_entry(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_entry((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_ENTRY_IS_NULL);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_all_entries(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_all_entries((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static int apr_emit_error(void *const object,
                          const struct sea_turtle_integer *const key,
                          const struct sea_turtle_integer *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void
check_as_ordered_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_add(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void check_as_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_map_i_i_add(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_add(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_add(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_put_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_put_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_put(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_put(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_replace_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_replace_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_VALUE_IS_NULL);
}

static void check_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_replace(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_i_i_replace(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_ordered_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_replace(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_replace(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const struct sea_turtle_integer *const key) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    return mock();
}

static void check_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_ordered_map_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_remove(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_i_i_remove(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_remove(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_remove(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static int
all_emit_error(void *const object,
               const struct butterflyfish_stream_i_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_add_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_add_all(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_add_all(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_put_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_put_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_put_all(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_put_all(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_replace_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_replace_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_replace_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_replace_all(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_replace_all(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static int
rr_all_emit_error(void *const object,
                  const struct butterflyfish_stream_i *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_remove_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_remove_all(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_remove_all(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_retain_all(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_retain_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_retain_all(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_retain_all(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_merge_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_merge(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_merge_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_merge((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_merge_error_on_function_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_merge((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_FUNCTION_IS_NULL);
}

static int
merge_emit_error(void *const object,
                 const struct butterflyfish_stream_i_i *const other,
                 int (*const function)(
                         const struct sea_turtle_integer *,
                         const struct sea_turtle_integer *,
                         struct sea_turtle_integer **)) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(function);
    return mock();
}

static void check_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_merge(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_merge(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_merge(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int
contains_key_emit_error(const void *const object,
                        const struct sea_turtle_integer *const key,
                        bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void
check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_key(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_key_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_contains_key(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_contains_key(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int
contains_all_keys_emit_error(const void *const object,
                             const struct butterflyfish_stream_i *const other,
                             bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_contains_all_keys(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_all_keys_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_contains_all_keys(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_contains_all_keys(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const struct sea_turtle_integer *const key,
                          const struct sea_turtle_integer **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_ordered_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_get(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_i_i_get(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_get(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_get(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static int
get_entry_emit_error(const void *const object,
                     const struct sea_turtle_integer *const key,
                     const struct butterflyfish_map_entry_i_i **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(key);
    assert_non_null(out);
    return mock();
}

static void check_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_get_entry(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_i_i_get_entry(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_get_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_entry_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_i_i_get_entry(
                    (struct butterflyfish_ordered_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ordered_map_i_i.map_i_i.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_i_i_get_entry(
                    (struct butterflyfish_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_keys(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_keys((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_values(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_values((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_ceiling_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_ceiling_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_ceiling_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_ceiling_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_floor_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_floor_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_floor_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_floor_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_floor_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_higher_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_higher_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_higher_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_higher_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_higher_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower_entry(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OBJECT_IS_NULL);
}

static void check_lower_entry_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower_entry(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_IS_NULL);
}

static void check_lower_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower_entry(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_OUT_IS_NULL);
}

static void check_lower_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_KEY_NOT_FOUND);
}

static void
check_lower_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_i_i sorted_map_i_i = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_i_i *sorted_map_i_i;
    };
    struct object instance = {
            .sorted_map_i_i = &sorted_map_i_i
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_i_i_lower_entry(
                    (struct butterflyfish_sorted_map_i_i *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_I_I_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_sorted_map_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_ordered_map_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_map_first_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_sorted_map_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_ordered_map_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_map_last_error_on_map_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_entry_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_sorted_map_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_ordered_map_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_map_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_entry_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_sorted_map_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_ordered_map_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_map_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_entry_error_on_object_is_null),
            cmocka_unit_test(check_remove_entry_error_on_entry_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_other_is_null),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_key_is_null),
            cmocka_unit_test(check_add_error_on_value_is_null),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_ordered_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_error_on_object_is_null),
            cmocka_unit_test(check_put_error_on_key_is_null),
            cmocka_unit_test(check_put_error_on_value_is_null),
            cmocka_unit_test(check_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_object_is_null),
            cmocka_unit_test(check_replace_error_on_key_is_null),
            cmocka_unit_test(check_replace_error_on_value_is_null),
            cmocka_unit_test(check_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_ordered_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_key_is_null),
            cmocka_unit_test(check_remove_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_remove_error_on_key_not_found),
            cmocka_unit_test(check_as_map_remove_error_on_key_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_key_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_all_error_on_object_is_null),
            cmocka_unit_test(check_put_all_error_on_key_is_null),
            cmocka_unit_test(check_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_put_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_all_error_on_object_is_null),
            cmocka_unit_test(check_replace_all_error_on_key_is_null),
            cmocka_unit_test(check_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_replace_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_key_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_key_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_merge_error_on_object_is_null),
            cmocka_unit_test(check_merge_error_on_other_is_null),
            cmocka_unit_test(check_merge_error_on_function_is_null),
            cmocka_unit_test(check_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_merge_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_key_error_on_object_is_null),
            cmocka_unit_test(check_contains_key_error_on_other_is_null),
            cmocka_unit_test(check_contains_key_error_on_out_is_null),
            cmocka_unit_test(check_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_contains_key_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_keys_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_contains_all_keys_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_key_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_key_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_key_not_found),
            cmocka_unit_test(check_floor_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_key_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_key_not_found),
            cmocka_unit_test(check_higher_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_key_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_key_not_found),
            cmocka_unit_test(check_lower_error_on_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_entry_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_key_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_entry_error_on_object_is_null),
            cmocka_unit_test(check_floor_entry_error_on_key_is_null),
            cmocka_unit_test(check_floor_entry_error_on_out_is_null),
            cmocka_unit_test(check_floor_entry_error_on_key_not_found),
            cmocka_unit_test(check_floor_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_entry_error_on_object_is_null),
            cmocka_unit_test(check_higher_entry_error_on_key_is_null),
            cmocka_unit_test(check_higher_entry_error_on_out_is_null),
            cmocka_unit_test(check_higher_entry_error_on_key_not_found),
            cmocka_unit_test(check_higher_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_entry_error_on_object_is_null),
            cmocka_unit_test(check_lower_entry_error_on_key_is_null),
            cmocka_unit_test(check_lower_entry_error_on_out_is_null),
            cmocka_unit_test(check_lower_entry_error_on_key_not_found),
            cmocka_unit_test(check_lower_entry_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
