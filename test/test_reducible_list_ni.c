#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_reducible_list_ni reducible_list = {};
    const struct butterflyfish_stream_ni *stream;
    assert_int_equal(butterflyfish_reducible_list_ni_as_stream(
            &reducible_list, &stream), 0);
    assert_ptr_equal(&reducible_list, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_reducible_list_ni reducible_list = {};
    const struct butterflyfish_collection_ni *collection;
    assert_int_equal(butterflyfish_reducible_list_ni_as_collection(
            &reducible_list, &collection), 0);
    assert_ptr_equal(&reducible_list, collection);
}

static void check_as_fixed_list_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_fixed_list(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_fixed_list_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_as_fixed_list((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_as_fixed_list(void **state) {
    struct butterflyfish_reducible_list_ni reducible_list = {};
    struct butterflyfish_fixed_list_ni *fixed_list;
    assert_int_equal(butterflyfish_reducible_list_ni_as_fixed_list(
            &reducible_list, &fixed_list), 0);
    assert_ptr_equal(&reducible_list, fixed_list);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_count(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_count((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_reducible_list_ni_count(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_count_as_fixed_list(void **state) {
    srand(time(NULL));
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_fixed_list_ni_count(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_count_as_collection(void **state) {
    srand(time(NULL));
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_ni_count(
                    (const struct butterflyfish_collection_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static int fl_emit_error(const void *const object,
                         const uintmax_t **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_reducible_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_list_ni_first(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
}

static void
check_as_fixed_list_first_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_ni_first(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_first(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_ni_first(
                    (const struct butterflyfish_stream_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_first(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_first((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_last(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_last((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_reducible_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_list_ni_last(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
}

static void
check_as_fixed_list_last_error_on_fixed_list_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_fixed_list_ni_last(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_LIST_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_LIST_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_last(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const uintmax_t *const item,
                         const uintmax_t **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_list_ni_next(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_fixed_list_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_ni_next(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_next(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_ni_next(
                    (const struct butterflyfish_stream_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_list_ni_prev(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_fixed_list_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_fixed_list_ni_prev(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_prev(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_get(NULL, 0, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_get((void *) 1, 0, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const uintmax_t at,
                          const uintmax_t **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_ni_get(
                    (const struct butterflyfish_reducible_list_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_get_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_ni_get(
                    (const struct butterflyfish_fixed_list_ni *) &instance,
                    0,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_set(NULL, 0, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static int set_emit_error(void *const object,
                          const uintmax_t at,
                          const uintmax_t value) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_set_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_ni_set(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_set_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_ni_set(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static void check_set_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_reducible_list_ni_set(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_fixed_list_set_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_fixed_list_ni_set(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_reducible_list_ni_set(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
}

static void
check_as_fixed_list_set_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set = set_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_emit_error);
    will_return(set_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_fixed_list_ni_set(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    0,
                    0),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_VALUE_IS_INVALID);
}

static void check_set_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_set_item(
                    NULL, (void *) 1, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_set_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_set_item(
                    (void *) 1, NULL, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_NULL);
}

static int set_item_emit_error(void *const object,
                               uintmax_t *const item,
                               const uintmax_t value) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return mock();
}

static void check_set_item_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_reducible_list_ni_set_item(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_set_item_as_fixed_list_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_FIXED_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_fixed_list_ni_set_item(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_set_item_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_reducible_list_ni_set_item(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
}

static void
check_set_item_as_fixed_list_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.set_item = set_item_emit_error,
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(set_item_emit_error);
    will_return(set_item_emit_error,
                BUTTERFLYFISH_FIXED_LIST_NI_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_fixed_list_ni_set_item(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_VALUE_IS_INVALID);
}

static void check_at_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_at(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_at_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_at((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_NULL);
}

static void check_at_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_at((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OUT_IS_NULL);
}

static int at_emit_error(const void *const object,
                         const uintmax_t *const item,
                         uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_at_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.at = at_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(at_emit_error);
    will_return(at_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_ni_at(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void
check_as_fixed_list_at_error_on_item_is_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .fixed_list_ni.at = at_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(at_emit_error);
    will_return(at_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_fixed_list_ni_at(
                    (struct butterflyfish_fixed_list_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_FIXED_LIST_NI_ERROR_ITEM_IS_OUT_OF_BOUNDS);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove(NULL, 0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static int remove_emit_error(void *const object,
                             const uintmax_t at) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_remove_error_on_index_out_of_bounds(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    0),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_INDEX_IS_OUT_OF_BOUNDS);
}

static int remove(void *const object,
                  const uintmax_t at) {
    function_called();
    assert_non_null(object);
    return 0;
}

static void check_remove(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .remove = remove
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(remove);
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove(
                    (struct butterflyfish_reducible_list_ni *) &instance, 0),
            0);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_ITEM_IS_NULL);
}

static int remove_item(void *const object,
                       const uintmax_t *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return 0;
}

static void check_remove_item(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .remove_item = remove_item
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(remove_item);
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_item(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_items_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_REDUCIBLE_LIST_NI_ERROR_OTHER_IS_NULL);
}

static int
remove_all_items(void *const object,
                 const struct butterflyfish_stream_ni *const stream) {
    function_called();
    assert_non_null(object);
    assert_non_null(stream);
    return 0;
}

static void check_remove_items(void **state) {
    const struct butterflyfish_reducible_list_ni reducible_list_ni = {
            .remove_all_items = remove_all_items
    };
    struct object {
        const struct butterflyfish_reducible_list_ni *reducible_list_ni;
    };
    struct object instance = {
            .reducible_list_ni = &reducible_list_ni
    };
    expect_function_call(remove_all_items);
    assert_int_equal(
            butterflyfish_reducible_list_ni_remove_all_items(
                    (struct butterflyfish_reducible_list_ni *) &instance,
                    (void *) 1),
            0);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_fixed_list_error_on_object_is_null),
            cmocka_unit_test(check_as_fixed_list_error_on_out_is_null),
            cmocka_unit_test(check_as_fixed_list),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_count_as_fixed_list),
            cmocka_unit_test(check_count_as_collection),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_reducible_list_is_empty),
            cmocka_unit_test(check_as_fixed_list_first_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_reducible_list_is_empty),
            cmocka_unit_test(check_as_fixed_list_last_error_on_fixed_list_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_fixed_list_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_fixed_list_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out),
            cmocka_unit_test(check_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_get_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_object_is_null),
            cmocka_unit_test(check_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_set_error_on_index_out_of_bounds),
            cmocka_unit_test(check_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_as_fixed_list_set_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_error_on_value_is_invalid),
            cmocka_unit_test(check_as_fixed_list_set_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_error_on_object_is_null),
            cmocka_unit_test(check_set_item_error_on_item_is_null),
            cmocka_unit_test(check_set_item_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_as_fixed_list_error_on_memory_allocation_failed),
            cmocka_unit_test(check_set_item_error_on_value_is_invalid),
            cmocka_unit_test(check_set_item_as_fixed_list_error_on_value_is_invalid),
            cmocka_unit_test(check_at_error_on_object_is_null),
            cmocka_unit_test(check_at_error_on_item_is_null),
            cmocka_unit_test(check_at_error_on_out_is_null),
            cmocka_unit_test(check_at_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_as_fixed_list_at_error_on_item_is_out_of_bounds),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_index_out_of_bounds),
            cmocka_unit_test(check_remove),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_items_error_on_other_is_null),
            cmocka_unit_test(check_remove_items),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
