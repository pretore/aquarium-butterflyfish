#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_sorted_map_ni_ni sorted_map = {};
    const struct butterflyfish_stream_ni_ni *stream;
    assert_int_equal(butterflyfish_sorted_map_ni_ni_as_stream(
            &sorted_map, &stream), 0);
    assert_ptr_equal(&sorted_map, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_sorted_map_ni_ni sorted_map = {};
    const struct butterflyfish_collection_ni_ni *collection;
    assert_int_equal(butterflyfish_sorted_map_ni_ni_as_collection(
            &sorted_map, &collection), 0);
    assert_ptr_equal(&sorted_map, collection);
}

static void check_as_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_map(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_map((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_as_map(void **state) {
    struct butterflyfish_sorted_map_ni_ni sorted_map = {};
    struct butterflyfish_map_ni_ni *map;
    assert_int_equal(butterflyfish_sorted_map_ni_ni_as_map(
            &sorted_map, &map), 0);
    assert_ptr_equal(&sorted_map, map);
}

static void check_as_ordered_map_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_ordered_map(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_ordered_map_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_as_ordered_map((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_as_ordered_map(void **state) {
    struct butterflyfish_sorted_map_ni_ni sorted_map = {};
    struct butterflyfish_ordered_map_ni_ni *ordered_map;
    assert_int_equal(butterflyfish_sorted_map_ni_ni_as_ordered_map(
            &sorted_map, &ordered_map), 0);
    assert_ptr_equal(&sorted_map, ordered_map);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_count(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_count((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int count(const void *const object, uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    *out = mock();
    return 0;
}

static void check_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.count = count
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_count(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_ordered_map_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.count = count
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_count(
                    (const struct butterflyfish_ordered_map_ni_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_map_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.count = count
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_map_ni_ni_count(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.count = count
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_ni_ni_count(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_first(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_first((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
fl_emit_error(const void *const object,
              const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_first(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_sorted_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_first(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_first(
                    (const struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_first_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_ni_ni_first(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_ni_first(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.first
            = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_ni_ni_first(
                    (const struct butterflyfish_stream_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_NI_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_last(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_last((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_last(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_sorted_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_last(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_ordered_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_last(
                    (const struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void check_as_map_last_error_on_map_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_map_ni_ni_last(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MAP_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_ni_last(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
np_emit_error(const void *const object,
              const struct butterflyfish_map_entry_ni_ni *const entry,
              const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .next = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_next(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_sorted_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_next(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_next(
                    (const struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_ni_ni_next(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_ni_next(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.stream_ni_ni.next
            = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_ni_ni_next(
                    (const struct butterflyfish_stream_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_prev(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_sorted_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_prev(
                    (const struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_ordered_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_prev(
                    (const struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_map_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_map_ni_ni_prev(
                    (const struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.collection_ni_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_ni_prev(
                    (const struct butterflyfish_collection_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_NI_ERROR_END_OF_SEQUENCE);
}

static void check_remove_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_entry(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_entry_error_on_entry_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_entry((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_ENTRY_IS_NULL);
}

static int
remove_entry(void *const object,
             const struct butterflyfish_map_entry_ni_ni *const entry) {
    function_called();
    assert_non_null(object);
    assert_non_null(entry);
    return 0;
}

static void check_remove_entry(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_entry = remove_entry
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_entry);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_ordered_map_remove_entry(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_entry = remove_entry
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_entry);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_remove_entry(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_map_remove_entry(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_entry = remove_entry
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_entry);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_entry(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_all_entries_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all_entries(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_entries_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all_entries((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static int
remove_all_entries(void *const object,
                   const struct butterflyfish_stream_ni_ni *const stream) {
    function_called();
    assert_non_null(object);
    assert_non_null(stream);
    return 0;
}

static void check_remove_all_entries(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all_entries = remove_all_entries
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_all_entries);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all_entries(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_ordered_map_remove_all_entries(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all_entries = remove_all_entries
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_all_entries);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_remove_all_entries(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_map_remove_all_entries(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all_entries = remove_all_entries
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_all_entries);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all_entries(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add(NULL, 0, 0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static int apr_emit_error(void *const object,
                          const uintmax_t key,
                          const uintmax_t value) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
}

static void
check_as_ordered_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_add(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
}

static void check_as_map_add_error_on_key_already_exists(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_map_ni_ni_add(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_add(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_add(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_put(NULL, 0, 0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_put(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_put(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_map_put_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_put(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace(NULL, 0, 0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_replace(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_replace_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_ordered_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_replace(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace = apr_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(apr_emit_error);
    will_return(apr_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove(NULL, 0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const uintmax_t key) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_ordered_map_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_remove(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_remove_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_remove(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static int
all_emit_error(void *const object,
               const struct butterflyfish_stream_ni_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_add_all(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_add_all(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.add_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_add_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_put_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_put_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_put_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_put_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_put_all(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_put_all(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_put_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.put_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_put_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_replace_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_replace_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_replace_all(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_replace_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_replace_all(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_replace_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.replace_all = all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(all_emit_error);
    will_return(all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_replace_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static int
rr_all_emit_error(void *const object,
                  const struct butterflyfish_stream_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_remove_all(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_remove_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_remove_all(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.remove_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_remove_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_key_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_retain_all(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_retain_all_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_retain_all(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.retain_all = rr_all_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(rr_all_emit_error);
    will_return(rr_all_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_retain_all(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_merge_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_merge(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_merge_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_merge((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_merge_error_on_function_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_merge((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_FUNCTION_IS_NULL);
}

static int
merge_emit_error(void *const object,
                 const struct butterflyfish_stream_ni_ni *const other,
                 int (*const function)(
                         const uintmax_t,
                         const uintmax_t,
                         uintmax_t *)) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(function);
    return mock();
}

static void check_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_merge(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_merge(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_merge_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.merge = merge_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(merge_emit_error);
    will_return(merge_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_merge(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_key_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_key(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_contains_key_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_key((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
contains_key_emit_error(const void *const object,
                        const uintmax_t key,
                        bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void
check_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_key(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_key_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_contains_key(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_key_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_key = contains_key_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_key_emit_error);
    will_return(contains_key_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_key(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_all_keys(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_keys_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_all_keys(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_all_keys(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
contains_all_keys_emit_error(const void *const object,
                             const struct butterflyfish_stream_ni *const other,
                             bool *out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_contains_all_keys(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_contains_all_keys_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_contains_all_keys(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_contains_all_keys_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.contains_all_keys
            = contains_all_keys_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(contains_all_keys_emit_error);
    will_return(contains_all_keys_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_contains_all_keys(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const uintmax_t key,
                          const uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_ordered_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_get(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_get(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_get(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_get(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get_entry(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_get_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get_entry((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int
get_entry_emit_error(const void *const object,
                     const uintmax_t key,
                     const struct butterflyfish_map_entry_ni_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_as_ordered_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_get_entry(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_as_map_get_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_get_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_ordered_map_get_entry_error_on_memory_allocation_failed(
        void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_get_entry(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_map_get_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.get_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_map_ni_ni_get_entry(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_keys_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_keys(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_keys_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_keys((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int keys(void *const object,
                struct butterflyfish_sorted_set_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return 0;
}

static void check_keys(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .keys = keys
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(keys);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_keys(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_values_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_values(NULL, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_values_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_values((void *) 1, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static int values(void *const object,
                  struct butterflyfish_reducible_list_ni **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return 0;
}

static void check_values(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.values = values
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(values);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_values(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_ordered_map_values(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.values = values
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(values);
    assert_int_equal(
            butterflyfish_ordered_map_ni_ni_values(
                    (struct butterflyfish_ordered_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_as_map_values(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ordered_map_ni_ni.map_ni_ni.values = values
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(values);
    assert_int_equal(
            butterflyfish_map_ni_ni_values(
                    (struct butterflyfish_map_ni_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_ceiling_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_ceiling_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_ceiling_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ceiling = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_floor_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_floor_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_floor_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .floor = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_higher_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_higher_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_higher_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .higher = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower(NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_lower_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower((void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_lower_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void check_lower_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .lower = get_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_ceiling_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling_entry(
                    NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_ceiling_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling_entry(
                    (void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_ceiling_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_ceiling_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .ceiling_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_ceiling_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_floor_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor_entry(
                    NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_floor_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor_entry(
                    (void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_floor_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_floor_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .floor_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_floor_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_higher_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher_entry(
                    NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_higher_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher_entry(
                    (void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_higher_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_higher_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .higher_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_higher_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_lower_entry_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower_entry(
                    NULL, 0, (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OBJECT_IS_NULL);
}

static void check_lower_entry_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower_entry(
                    (void *) 1, 0, NULL),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_OUT_IS_NULL);
}

static void check_lower_entry_error_on_key_not_found(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_KEY_NOT_FOUND);
}

static void
check_lower_entry_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_sorted_map_ni_ni sorted_map_ni_ni = {
            .lower_entry = get_entry_emit_error
    };
    struct object {
        const struct butterflyfish_sorted_map_ni_ni *sorted_map_ni_ni;
    };
    struct object instance = {
            .sorted_map_ni_ni = &sorted_map_ni_ni
    };
    expect_function_call(get_entry_emit_error);
    will_return(get_entry_emit_error,
                BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_sorted_map_ni_ni_lower_entry(
                    (struct butterflyfish_sorted_map_ni_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_SORTED_MAP_NI_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_map_error_on_object_is_null),
            cmocka_unit_test(check_as_map_error_on_out_is_null),
            cmocka_unit_test(check_as_map),
            cmocka_unit_test(check_as_ordered_map_error_on_object_is_null),
            cmocka_unit_test(check_as_ordered_map_error_on_out_is_null),
            cmocka_unit_test(check_as_ordered_map),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_ordered_map_count),
            cmocka_unit_test(check_as_map_count),
            cmocka_unit_test(check_as_collection_count),
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
            cmocka_unit_test(check_remove_entry),
            cmocka_unit_test(check_as_ordered_map_remove_entry),
            cmocka_unit_test(check_as_map_remove_entry),
            cmocka_unit_test(check_remove_all_entries_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_entries_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_entries),
            cmocka_unit_test(check_as_ordered_map_remove_all_entries),
            cmocka_unit_test(check_as_map_remove_all_entries),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_ordered_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_as_map_add_error_on_key_already_exists),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_put_error_on_object_is_null),
            cmocka_unit_test(check_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_put_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_object_is_null),
            cmocka_unit_test(check_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_as_map_replace_error_on_key_not_found),
            cmocka_unit_test(check_ordered_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_replace_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
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
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_error_on_key_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_entry_error_on_object_is_null),
            cmocka_unit_test(check_get_entry_error_on_out_is_null),
            cmocka_unit_test(check_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_as_map_get_entry_error_on_key_not_found),
            cmocka_unit_test(check_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_ordered_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_map_get_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_keys_error_on_object_is_null),
            cmocka_unit_test(check_keys_error_on_out_is_null),
            cmocka_unit_test(check_keys),
            cmocka_unit_test(check_values_error_on_object_is_null),
            cmocka_unit_test(check_values_error_on_out_is_null),
            cmocka_unit_test(check_values),
            cmocka_unit_test(check_as_ordered_map_values),
            cmocka_unit_test(check_as_map_values),
            cmocka_unit_test(check_ceiling_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_error_on_object_is_null),
            cmocka_unit_test(check_floor_error_on_out_is_null),
            cmocka_unit_test(check_floor_error_on_key_not_found),
            cmocka_unit_test(check_floor_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_error_on_object_is_null),
            cmocka_unit_test(check_higher_error_on_out_is_null),
            cmocka_unit_test(check_higher_error_on_key_not_found),
            cmocka_unit_test(check_higher_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_error_on_object_is_null),
            cmocka_unit_test(check_lower_error_on_out_is_null),
            cmocka_unit_test(check_lower_error_on_key_not_found),
            cmocka_unit_test(check_lower_error_on_memory_allocation_failed),
            cmocka_unit_test(check_ceiling_entry_error_on_object_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_out_is_null),
            cmocka_unit_test(check_ceiling_entry_error_on_key_not_found),
            cmocka_unit_test(check_ceiling_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_floor_entry_error_on_object_is_null),
            cmocka_unit_test(check_floor_entry_error_on_out_is_null),
            cmocka_unit_test(check_floor_entry_error_on_key_not_found),
            cmocka_unit_test(check_floor_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_higher_entry_error_on_object_is_null),
            cmocka_unit_test(check_higher_entry_error_on_out_is_null),
            cmocka_unit_test(check_higher_entry_error_on_key_not_found),
            cmocka_unit_test(check_higher_entry_error_on_memory_allocation_failed),
            cmocka_unit_test(check_lower_entry_error_on_object_is_null),
            cmocka_unit_test(check_lower_entry_error_on_out_is_null),
            cmocka_unit_test(check_lower_entry_error_on_key_not_found),
            cmocka_unit_test(check_lower_entry_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
