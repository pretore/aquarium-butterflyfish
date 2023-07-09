#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <butterflyfish.h>

#include <test/cmocka.h>

static void check_as_stream_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_stream(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_stream_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_stream((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_as_stream(void **state) {
    struct butterflyfish_queue_ni queue = {};
    const struct butterflyfish_stream_ni *stream;
    assert_int_equal(butterflyfish_queue_ni_as_stream(&queue, &stream), 0);
    assert_ptr_equal(&queue, stream);
}

static void check_as_collection_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_collection(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_collection_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_collection((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_as_collection(void **state) {
    struct butterflyfish_queue_ni queue = {};
    const struct butterflyfish_collection_ni *collection;
    assert_int_equal(butterflyfish_queue_ni_as_collection(
            &queue, &collection), 0);
    assert_ptr_equal(&queue, collection);
}

static void check_as_reducible_queue_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_reducible_queue(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_as_reducible_queue_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_as_reducible_queue((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_as_reducible_queue(void **state) {
    struct butterflyfish_queue_ni queue = {};
    struct butterflyfish_reducible_queue_ni *reducible_queue;
    assert_int_equal(butterflyfish_queue_ni_as_reducible_queue(
            &queue, &reducible_queue), 0);
    assert_ptr_equal(&queue, reducible_queue);
}

static void check_count_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_count(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_count_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_count((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_queue_ni_count(
                    (const struct butterflyfish_queue_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_reducible_queue_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(count);
    const uintmax_t check = abs(rand());
    will_return(count, check);
    uintmax_t out;
    assert_int_equal(
            butterflyfish_reducible_queue_ni_count(
                    (const struct butterflyfish_reducible_queue_ni *) &instance,
                    &out),
            0);
    assert_int_equal(out, check);
}

static void check_as_collection_count(void **state) {
    srand(time(NULL));
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.count = count
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
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

static void check_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_ni_first(
                    (const struct butterflyfish_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_first_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_ni_first(
                    (const struct butterflyfish_reducible_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_first_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_first(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_as_stream_first_error_on_stream_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.first = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_stream_ni_first(
                    (const struct butterflyfish_stream_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_ERROR_STREAM_IS_EMPTY);
}

static void check_first_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_first(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_first_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_first((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_last(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_last_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_last((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_ni_last(
                    (const struct butterflyfish_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_last_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_ni_last(
                    (const struct butterflyfish_reducible_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_collection_last_error_on_collection_is_empty(void **state) {
    const struct butterflyfish_collection_ni collection_ni = {
            .last = fl_emit_error
    };
    struct object {
        const struct butterflyfish_collection_ni *collection_ni;
    };
    struct object instance = {
            .collection_ni = &collection_ni
    };
    expect_function_call(fl_emit_error);
    will_return(fl_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_collection_ni_last(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_COLLECTION_IS_EMPTY);
}

static void check_next_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_next(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_next_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_next((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_ITEM_IS_NULL);
}

static void check_next_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_next((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
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
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_queue_ni_next(
                    (const struct butterflyfish_queue_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_queue_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_ni_next(
                    (const struct butterflyfish_reducible_queue_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_next(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_stream_next_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.stream_ni.next = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_stream_ni_next(
                    (const struct butterflyfish_stream_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_STREAM_NI_ERROR_END_OF_SEQUENCE);
}

static void check_prev_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_prev(NULL, (void *) 1, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_prev_error_on_item_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_prev((void *) 1, NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_ITEM_IS_NULL);
}

static void check_prev_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_prev((void *) 1, (void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static void check_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_queue_ni_prev(
                    (const struct butterflyfish_queue_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
}

static void
check_as_reducible_queue_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_reducible_queue_ni_prev(
                    (const struct butterflyfish_reducible_queue_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
}

static void check_as_collection_prev_error_on_end_of_sequence(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.collection_ni.prev = np_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(np_emit_error);
    will_return(np_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_END_OF_SEQUENCE);
    assert_int_equal(
            butterflyfish_collection_ni_prev(
                    (const struct butterflyfish_collection_ni *) &instance,
                    (void *) 1,
                    (void *) 1),
            BUTTERFLYFISH_COLLECTION_NI_ERROR_END_OF_SEQUENCE);
}

static void check_remove_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_remove(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_remove_error_on_out_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_remove((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OUT_IS_NULL);
}

static int
remove_emit_error(void *const object,
                  uintmax_t *const out) {
    function_called();
    assert_non_null(object);
    assert_non_null(out);
    return mock();
}

static void check_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_queue_ni_remove(
                    (struct butterflyfish_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void
check_as_reducible_queue_remove_error_on_queue_is_empty(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .reducible_queue_ni.remove = remove_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(remove_emit_error);
    will_return(remove_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
    assert_int_equal(
            butterflyfish_reducible_queue_ni_remove(
                    (struct butterflyfish_reducible_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_REDUCIBLE_QUEUE_NI_ERROR_QUEUE_IS_EMPTY);
}

static void check_add_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_add(NULL, 0),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static int add_emit_error(void *const object,
                          const uintmax_t value) {
    function_called();
    assert_non_null(object);
    return mock();
}

static void check_add_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .add = add_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(add_emit_error);
    will_return(add_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_queue_ni_add(
                    (struct butterflyfish_queue_ni *) &instance,
                    0),
            BUTTERFLYFISH_QUEUE_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

static void check_add_error_on_value_is_invalid(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .add = add_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(add_emit_error);
    will_return(add_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_VALUE_IS_INVALID);
    assert_int_equal(
            butterflyfish_queue_ni_add(
                    (struct butterflyfish_queue_ni *) &instance,
                    0),
            BUTTERFLYFISH_QUEUE_NI_ERROR_VALUE_IS_INVALID);
}

static int
add_all_emit_error(void *const object,
                   const struct butterflyfish_stream_ni *const other) {
    function_called();
    assert_non_null(object);
    assert_non_null(other);
    return mock();
}

static void check_add_all_error_on_object_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_add_all(NULL, (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OBJECT_IS_NULL);
}

static void check_add_all_error_on_other_is_null(void **state) {
    assert_int_equal(
            butterflyfish_queue_ni_add_all((void *) 1, NULL),
            BUTTERFLYFISH_QUEUE_NI_ERROR_OTHER_IS_NULL);
}

static void check_add_all_error_on_memory_allocation_failed(void **state) {
    const struct butterflyfish_queue_ni queue_ni = {
            .add_all = add_all_emit_error
    };
    struct object {
        const struct butterflyfish_queue_ni *queue_ni;
    };
    struct object instance = {
            .queue_ni = &queue_ni
    };
    expect_function_call(add_all_emit_error);
    will_return(add_all_emit_error,
                BUTTERFLYFISH_QUEUE_NI_ERROR_MEMORY_ALLOCATION_FAILED);
    assert_int_equal(
            butterflyfish_queue_ni_add_all(
                    (struct butterflyfish_queue_ni *) &instance,
                    (void *) 1),
            BUTTERFLYFISH_QUEUE_NI_ERROR_MEMORY_ALLOCATION_FAILED);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(check_as_stream_error_on_object_is_null),
            cmocka_unit_test(check_as_stream_error_on_out_is_null),
            cmocka_unit_test(check_as_stream),
            cmocka_unit_test(check_as_collection_error_on_object_is_null),
            cmocka_unit_test(check_as_collection_error_on_out_is_null),
            cmocka_unit_test(check_as_collection),
            cmocka_unit_test(check_as_reducible_queue_error_on_object_is_null),
            cmocka_unit_test(check_as_reducible_queue_error_on_out_is_null),
            cmocka_unit_test(check_as_reducible_queue),
            cmocka_unit_test(check_count_error_on_object_is_null),
            cmocka_unit_test(check_count_error_on_out_is_null),
            cmocka_unit_test(check_count),
            cmocka_unit_test(check_as_reducible_queue_count),
            cmocka_unit_test(check_as_collection_count),
            cmocka_unit_test(check_first_error_on_object_is_null),
            cmocka_unit_test(check_first_error_on_out_is_null),
            cmocka_unit_test(check_first_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_first_error_on_queue_is_empty),
            cmocka_unit_test(check_as_collection_first_error_on_collection_is_empty),
            cmocka_unit_test(check_as_stream_first_error_on_stream_is_empty),
            cmocka_unit_test(check_last_error_on_object_is_null),
            cmocka_unit_test(check_last_error_on_out_is_null),
            cmocka_unit_test(check_last_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_last_error_on_queue_is_empty),
            cmocka_unit_test(check_as_collection_last_error_on_collection_is_empty),
            cmocka_unit_test(check_next_error_on_object_is_null),
            cmocka_unit_test(check_next_error_on_item_is_null),
            cmocka_unit_test(check_next_error_on_out_is_null),
            cmocka_unit_test(check_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_queue_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_next_error_on_end_of_sequence),
            cmocka_unit_test(check_as_stream_next_error_on_end_of_sequence),
            cmocka_unit_test(check_prev_error_on_object_is_null),
            cmocka_unit_test(check_prev_error_on_item_is_null),
            cmocka_unit_test(check_prev_error_on_out_is_null),
            cmocka_unit_test(check_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_reducible_queue_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_as_collection_prev_error_on_end_of_sequence),
            cmocka_unit_test(check_remove_error_on_object_is_null),
            cmocka_unit_test(check_remove_error_on_out_is_null),
            cmocka_unit_test(check_remove_error_on_queue_is_empty),
            cmocka_unit_test(check_as_reducible_queue_remove_error_on_queue_is_empty),
            cmocka_unit_test(check_add_error_on_object_is_null),
            cmocka_unit_test(check_add_error_on_memory_allocation_failed),
            cmocka_unit_test(check_add_error_on_value_is_invalid),
            cmocka_unit_test(check_add_all_error_on_object_is_null),
            cmocka_unit_test(check_add_all_error_on_other_is_null),
            cmocka_unit_test(check_add_all_error_on_memory_allocation_failed),
    };
    //cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests(tests, NULL, NULL);
}
