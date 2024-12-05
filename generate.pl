#!/usr/bin/perl -W

use strict;
use warnings FATAL => 'all';

my constant %project = (
    name => "butterflyfish",
);

my constant @basic_types =
    (
        # { # native integer
        #     declaration => "uintmax_t",
        #     value       => "uintmax_t *",
        #     code        => "ni",
        # }, { # pointer
        #     declaration => "void *",
        #     value       => "void *",
        #     code        => "p",
        # },
        { # integer
            declaration => "struct sea_turtle_integer",
            value       => "struct sea_turtle_integer *",
            includes    => ["<sea-turtle.h>"],
            code        => "i",
        },
        #     { # string
        #     declaration => "struct sea_turtle_string",
        #     value       => "struct sea_turtle_string *",
        #     includes    => ["<sea-turtle.h>"],
        #     code        => "s",
        # },
        # { # strong reference
        #     declaration => "struct triggerfish_strong",
        #     value       => "struct triggerfish_strong *",
        #     includes    => ["<triggerfish.h>"],
        #     code        => "sr",
        # },
        # { # weak reference
        #     declaration => "struct triggerfish_weak",
        #     value       => "struct triggerfish_weak *",
        #     includes    => ["<triggerfish.h>"],
        #     code        => "wr",
        # }
    );

# Generate the map entity types
my @entity_types;
for my $k (@basic_types) {
    for my $v (@basic_types) {
        my $code = $k->{'code'} . "_" . $v->{'code'};
        my $declaration = "struct " . $project{'name'} . "_map_" . $code . "_entry";
        my %entity = (
            declaration => $declaration,
            value       => $declaration . " *",
            k           => $k,
            v           => $v,
            code        => $code,
        );
        my %tmp;
        for my $i ($k, $v) {
            if (!exists($i->{'includes'})) {
                next;
            }
            for my $o (@{$i->{includes}}) {
                $tmp{$o} = 1;
            }
        }
        if (%tmp) {
            my @includes = sort(keys %tmp);
            $entity{'includes'} = \@includes;
        }
        push(@entity_types, \%entity);
    }
}
for my $i (@entity_types) {
    my $content;
    open(my $fi, '<', "template/include/" . $project{'name'} . "/map_entry.h")
        or die "Cannot open file: $!";
    {
        local $/;
        $content = <$fi>;
    }
    close($fi);
    undef $fi;
    # define variables used by the template
    my constant $t = $i->{'code'};
    my constant $T = uc($t);
    my constant $k = $i->{'k'}{'declaration'};
    my constant $v = $i->{'v'}{'declaration'};
    my constant @includes = exists($i->{'includes'})
        ? map {"#include " . $_ . "\n"} @{$i->{'includes'}}
        : ();

    # interpolate '$' tokens
    $content =~ s/(\$[tTkv])\$/$1/eeg;
    # interpolate '@' tokens
    $content = eval qq{"$content"};
    $content =~ s/^(\s+)#include/#include/gm;
    $content =~ s/^#include/\n#include/m;

    open(my $fo, '>', "include/" . $project{'name'} . "/map_" . $t . "_entry.h")
        or die "Cannot open file: $!";
    print $fo $content;
    close($fo);
}

sub collection_interpolate_h_file {
    my $args_hashref = shift;
    my $content = $args_hashref->{'content'};
    # define variables used by the header file template
    my constant $t = $args_hashref->{'code'};
    my constant $T = uc($t);
    my constant $v = $args_hashref->{'value'};
    my constant $d = (exists($args_hashref->{'declaration'})
        && $args_hashref->{'declaration'} =~ /^struct /)
        ? $args_hashref->{'declaration'} . ";"
        : q{};

    my constant $mkt;
    if (exists($args_hashref->{'map_key_code'})) {
        $mkt = $args_hashref->{'map_key_code'};
    }
    my constant $mkv;
    if (exists($args_hashref->{'map_key_value'})) {
        $mkv = $args_hashref->{'map_key_value'};
    }
    my constant $mvt;
    if (exists($args_hashref->{'map_value_code'})) {
        $mvt = $args_hashref->{'map_value_code'};
    }
    my constant $mvv;
    if (exists($args_hashref->{'map_value_value'})) {
        $mvv = $args_hashref->{'map_value_value'};
    }

    # interpolate '$' tokens
    $content =~ s/(\$[tTvd])\$/$1/eeg;
    $content =~ s/(\$m[kv][tdv])\$/$1/eeg;

    return $content;
}

sub collection_interpolate_c_file {
    my $args_hashref = shift;
    my $content = $args_hashref->{'content'};
    # define variables used by the source file template
    my constant $t = $args_hashref->{'code'};
    my constant $T = uc($t);
    my constant $v = $args_hashref->{'value'};
    my constant $p = ($v =~ /\*$/);
    my constant @includes = exists($args_hashref->{'includes'})
        ? map {"#include " . $_ . "\n"} @{$args_hashref->{'includes'}}
        : ();

    my constant $mkt;
    if (exists($args_hashref->{'map_key_code'})) {
        $mkt = $args_hashref->{'map_key_code'};
    }
    my constant $mkv;
    if (exists($args_hashref->{'map_key_value'})) {
        $mkv = $args_hashref->{'map_key_value'};
    }
    my constant $mvt;
    if (exists($args_hashref->{'map_value_code'})) {
        $mvt = $args_hashref->{'map_value_code'};
    }
    my constant $mvv;
    if (exists($args_hashref->{'map_value_value'})) {
        $mvv = $args_hashref->{'map_value_value'};
    }

    # interpolate '$' tokens
    $content =~ s/(\$[tTv])\$/$1/eeg;
    $content =~ s/(\$m[kv][tv])\$/$1/eeg;

    # interpolate '@' tokens
    $content = eval qq{"$content"};
    $content =~ s/^(\s+)#include/#include/gm;

    return $content;
}

sub collection_generate_type {
    my $args_hashref = shift;
    my constant $source = $args_hashref->{'source'};
    my %params = (
        code        => $args_hashref->{'type'}{'code'},
        value       => $args_hashref->{'type'}{'value'},
        declaration => $args_hashref->{'type'}{'declaration'},
        includes    => $args_hashref->{'type'}{'includes'},
    );
    if (exists($args_hashref->{'type'}{'k'})) {
        my constant $k = $args_hashref->{'type'}{'k'};
        $params{'map_key_code'} = $k->{'code'};
        $params{'map_key_value'} = $k->{'value'};
    }
    if (exists($args_hashref->{'type'}{'v'})) {
        my constant $v = $args_hashref->{'type'}{'v'};
        $params{'map_value_code'} = $v->{'code'};
        $params{'map_value_value'} = $v->{'value'};
    }

    my $content;
    # source.h
    open(my $fi, '<', "template/include/" . $project{'name'} . "/" .
        $source . ".h") or die "Cannot open file: $!";
    {
        local $/;
        $content = <$fi>;
    }
    close($fi);
    $params{'content'} = $content;
    $content = collection_interpolate_h_file(\%params);
    open(my $fo, '>', "include/" . $project{'name'} . "/" . $source . "_" . $params{'code'} . ".h")
        or die "Cannot open file: $!";
    print $fo $content;
    close($fo);

    # source.c
    open($fi, '<', "template/src/" . $source . ".c")
        or die "Cannot open file: $!";
    {
        local $/;
        $content = <$fi>;
    }
    close($fi);
    $params{'content'} = $content;
    $content = collection_interpolate_c_file(\%params);
    open($fo, '>', "src/" . $source . "_" . $params{'code'} . ".c")
        or die "Cannot open file: $!";
    print $fo $content;
    close($fo);

    # test_source.c
    open($fi, '<', "template/test/test_" . $source . ".c")
        or die "Cannot open file: $!";
    {
        local $/;
        $content = <$fi>;
    }
    close($fi);
    $params{'content'} = $content;
    $content = collection_interpolate_c_file(\%params);
    open($fo, '>', "test/test_" . $source . "_" . $params{'code'} . ".c")
        or die "Cannot open file: $!";
    print $fo $content;
    close($fo);
}

# Get list of sources
opendir my $dir, "template/src" or die "Cannot open directory: $!";
my constant @types = map {s/\.c$//;$_} grep {/\.c$/} readdir $dir;
closedir $dir;
for my $i (@types) {
    for my $o (@entity_types) {
        my %params = (
            source => $i,
            type   => $o,
        );
        collection_generate_type(\%params);
    }
    if ($i =~ /map$/) {
        next;
    }
    for my $o (@basic_types) {
        my %params = (
            source => $i,
            type   => $o,
        );
        collection_generate_type(\%params);
    }
}

# TODO: generate project include file
# TODO: generate CMakeLists.txt file

