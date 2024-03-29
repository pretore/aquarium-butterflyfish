#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_set_p set = {};
    const struct butterflyfish_stream_p *stream;
    assert_int_equal(butterflyfish_set_p_as_stream(&set, &stream), 0);
    assert_ptr_equal(&set, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_set_p set = {};
    const struct butterflyfish_collection_p *collection;
    assert_int_equal(butterflyfish_set_p_as_collection(&set, &collection), 0);
    assert_ptr_equal(&set, collection);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_count(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_count((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_set_p set_p = {
            .collection_p.count = count
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_set_p_count(
                    (const struct butterflyfish_set_p *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_set_p set_p = {
            .collection_p.count = count
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_collection_p_count(
                    (const struct butterflyfish_collection_p *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_first(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_first((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static int fl_emit_error(const void *const object,
                         const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_first_error_on_set_is_empty(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_p_first(
                    (const struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_first(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_COLLECTION_IS_EMPTY);
}

static void
check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_p_first(
                    (const struct butterflyfish_stream_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_ERROR_STREAM_IS_EMPTY);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_last(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_last((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_set_is_empty(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_set_p_last(
                    (const struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_SET_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_p_last(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_COLLECTION_IS_EMPTY);
}

static void check_remove_item_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_item(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_item_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_item((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL);
}

static int remove_item(void *const object,
                       const void *const item) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    return 0;
}

static void check_remove_item(void **state) {
    const struct butterflyfish_set_p set_p = {
            .remove_item = remove_item
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(remove_item);
    assert_int_equal(
            butterflyfish_set_p_remove_item(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            0);
}

static void check_remove_all_items_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_all_items(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_items_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_all_items((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL);
}

static int
remove_all_items(void *const object,
                 const struct butterflyfish_stream_p *const items) {
    function_called();
    assert_non_null(object);
    assert_non_null(items);
    return 0;
}

static void check_remove_all_items(void **state) {
    const struct butterflyfish_set_p set_p = {
            .remove_all_items = remove_all_items
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(remove_all_items);
    assert_int_equal(
            butterflyfish_set_p_remove_all_items(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            0);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static int np_emit_error(const void *const object,
                         const void *const item,
                         const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(item);
    assert_non_null(out);
    return mock();
}

static void check_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_p_next(
                    (const struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_next(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.stream_p.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_p_next(
                    (const struct butterflyfish_stream_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_P_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_set_p_prev(
                    (const struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_set_p set_p = {
            .collection_p.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_p_prev(
                    (const struct butterflyfish_collection_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_P_ERROR_END_OF_SEQUENCE);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_add(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static int ar_emit_error(void *const object,
                         const void *const value) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    return mock();
}

static void check_add_error_on_value_already_exits(void **state) {
    const struct butterflyfish_set_p set_p = {
            .add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_VALUE_ALREADY_EXISTS);
    assert_int_equal(
            butterflyfish_set_p_add(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_VALUE_ALREADY_EXISTS);
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .add = ar_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_add(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_add_all((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL);
}

static int
ar_all_emit_error(void *const object,
                  const struct butterflyfish_stream_p *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .add_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_add_all(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_value_not_found(void **state) {
    const struct butterflyfish_set_p set_p = {
            .remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_VALUE_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_p_remove(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_VALUE_NOT_FOUND);
}

static void check_remove_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .remove = ar_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_emit_error);
    will_return(ar_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_remove(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_remove_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_all(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_remove_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_remove_all((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL);
}

static void check_remove_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .remove_all = ar_all_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(ar_all_emit_error);
    will_return(ar_all_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_remove_all(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_contains(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_contains_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_contains((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static int contains_emit_error(const void *const object,
                               const void *const value,
                               bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_contains_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .contains = contains_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(contains_emit_error);
    will_return(contains_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_contains(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_contains_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_contains_all(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_contains_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_contains_all((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL);
}

static void check_contains_all_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_contains_all((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static int
contains_all_emit_error(const void *const object,
                        const struct butterflyfish_stream_p *const other,
                        bool *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    assert_non_null(out);
    return mock();
}

static void
check_contains_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .contains_all = contains_all_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(contains_all_emit_error);
    will_return(contains_all_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_contains_all(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_retain_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_retain_all(NULL, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_retain_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_retain_all((void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OTHER_IS_NULL);
}

static int
retain_all_emit_error(void *const object,
                      const struct butterflyfish_stream_p *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void
check_retain_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .retain_all = retain_all_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(retain_all_emit_error);
    will_return(retain_all_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_retain_all(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_get_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_get(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_OBJECT_IS_NULL);
}

static void check_get_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_set_p_get((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_SET_P_ERROR_OUT_IS_NULL);
}

static int get_emit_error(const void *const object,
                          const void *const value,
                          const void **const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(value);
    assert_non_null(out);
    return mock();
}

static void check_get_error_on_item_not_found(void **state) {
    const struct butterflyfish_set_p set_p = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_ITEM_NOT_FOUND);
    assert_int_equal(
            butterflyfish_set_p_get(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_ITEM_NOT_FOUND);
}

static void check_get_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_set_p set_p = {
            .get = get_emit_error
    };
    struct object {
        const struct butterflyfish_set_p *set_p;
    };
    struct object instance = {
            .set_p = &set_p
    };
    expect_function_call(get_emit_error);
    will_return(get_emit_error,
                BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_set_p_get(
                    (struct butterflyfish_set_p *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_SET_P_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_collection_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_set_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_set_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_remove_item_error_on_object_is_null),
            cmocka_unit_test(check_remove_item_error_on_item_is_null),
            cmocka_unit_test(check_remove_item),
            cmocka_unit_test(check_remove_all_items_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_items_error_on_item_is_null),
            cmocka_unit_test(check_remove_all_items),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_value_already_exits),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_value_not_found),
            cmocka_unit_test(check_remove_error_on_memory_allocation_failed),
            cmocka_unit_test(check_remove_all_error_on_object_is_null),
            cmocka_unit_test(check_remove_all_error_on_other_is_null),
            cmocka_unit_test(check_remove_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_error_on_object_is_null),
            cmocka_unit_test(check_contains_error_on_out_is_null),
            cmocka_unit_test(check_contains_error_on_memory_allocation_failed),
            cmocka_unit_test(check_contains_all_error_on_object_is_null),
            cmocka_unit_test(check_contains_all_error_on_other_is_null),
            cmocka_unit_test(check_contains_all_error_on_out_is_null),
            cmocka_unit_test(check_contains_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_retain_all_error_on_object_is_null),
            cmocka_unit_test(check_retain_all_error_on_other_is_null),
            cmocka_unit_test(check_retain_all_error_on_memory_allocation_failed),
            cmocka_unit_test(check_get_error_on_object_is_null),
            cmocka_unit_test(check_get_error_on_out_is_null),
            cmocka_unit_test(check_get_error_on_item_not_found),
            cmocka_unit_test(check_get_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
