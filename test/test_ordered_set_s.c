#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_ordered_set_s ordered_set = {};
    const struct butterflyfish_stream_s *stream;
    assert_int_equal(butterflyfish_ordered_set_s_as_stream(
            &ordered_set, &stream), 0);
    assert_ptr_equal(&ordered_set, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_ordered_set_s ordered_set = {};
    const struct butterflyfish_collection_s *collection;
    assert_int_equal(butterflyfish_ordered_set_s_as_collection(
            &ordered_set, &collection), 0);
    assert_ptr_equal(&ordered_set, collection);
}

static void check_as_set_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_set(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_as_set_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_as_set((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static void check_as_set(void **state) {
    struct butterflyfish_ordered_set_s ordered_set = {};
    struct butterflyfish_set_s *set;
    assert_int_equal(butterflyfish_ordered_set_s_as_set(
            &ordered_set, &set), 0);
    assert_ptr_equal(&ordered_set, set);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_count(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_count((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.count = count
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_ordered_set_s_count(
                    (const struct butterflyfish_ordered_set_s *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_set_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.count = count
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_set_s_count(
                    (const struct butterflyfish_set_s *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.count = count
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_s_count(
                    (const struct butterflyfish_collection_s *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_first(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_first((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_s_first(
                    (const struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
}

static void check_as_set_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_s_first(
                    (const struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_first(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void
check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_s_first(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_last(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_last((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_ordered_set_s_last(
                    (const struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
}

static void check_as_set_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_s_last(
                    (const struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_s_last(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_COLLECTION_IS_EMPTY);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL);
}

static int remove_item(void *const object,
                       const struct sea_turtle_string *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return 0;
}

static void check_remove_item(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_item = remove_item
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(remove_item);
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_item(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            0);
}

static void check_as_set_remove_item(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_item = remove_item
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(remove_item);
    assert_int_equal(
            butterflyfish_set_s_remove_item(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL);
}

static int
remove_all_items(void *const object,
                 const struct butterflyfish_stream_s *const items) {
    function_called();
    assert_non_null(object);
    assert_non_null(items);
    return 0;
}

static void check_remove_all_items(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_all_items = remove_all_items
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(remove_all_items);
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all_items(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            0);
}

static void check_as_set_remove_all_items(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_all_items = remove_all_items
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(remove_all_items);
    assert_int_equal(
            butterflyfish_set_s_remove_all_items(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            0);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const struct sea_turtle_string *const item,
                         const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_s_next(
                    (const struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_s_next(
                    (const struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_next(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.stream_s.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_s_next(
                    (const struct butterflyfish_stream_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_S_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_ordered_set_s_prev(
                    (const struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_set_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_s_prev(
                    (const struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.collection_s.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_s_prev(
                    (const struct butterflyfish_collection_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_S_ERROR_END_OF_SEQUENCE);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_add(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_add_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_add((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL);
}

static int ar_emit_error(void *const object,
                         const struct sea_turtle_string *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_ordered_set_s_add(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_as_set_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_set_s_add(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_add(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_add(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_add_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL);
}

static int
ar_all_emit_error(void *const object,
                  const struct butterflyfish_stream_s *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_add_all(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_add_all(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_s_remove(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_NOT_FOUND);
}

static void check_as_set_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_s_remove(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_remove(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_remove(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_remove_all(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_remove_all(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static int contains_emit_error(const void *const object,
                               const struct sea_turtle_string *const value,
                               bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_contains(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_contains(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains_all(
                    NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains_all(
                    (void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_contains_all(
                    (void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static int
contains_all_emit_error(const void *const object,
                        const struct butterflyfish_stream_s *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_contains_all(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_contains_all(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OTHER_IS_NULL);
}

static int
retain_all_emit_error(void *const object,
                      const struct butterflyfish_stream_s *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_retain_all(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void
check_as_set_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_retain_all(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_value_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_get((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_VALUE_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_ordered_set_s_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const struct sea_turtle_string *const value,
                          const struct sea_turtle_string **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_ordered_set_s_get(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_NOT_FOUND);
}

static void check_as_set_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_s_get(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_ITEM_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_ordered_set_s_get(
                    (struct butterflyfish_ordered_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_as_set_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_ordered_set_s ordered_set_s = {
            .set_s.get = get_emit_error
    };
    struct object {
        const struct butterflyfish_ordered_set_s *ordered_set_s;
    };
    struct object instance = {
            .ordered_set_s = &ordered_set_s
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_ORDERED_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_s_get(
                    (struct butterflyfish_set_s *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_S_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_set_error_on_object_is_null),
            cmocka_unit_test(check_as_set_error_on_out_is_null),
            cmocka_unit_test(check_as_set),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_set_count),
            cmocka_unit_test(check_as_collection_count),
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
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_as_set_remove_item),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items),
            cmocka_unit_test(check_as_set_remove_all_items),
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
