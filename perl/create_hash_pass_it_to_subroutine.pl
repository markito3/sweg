#!/usr/bin/env perl
%section_hash = [];
$section_hash{title} = "this is the title";
$section_hash{comment} = "this is the comment";
@headings = ("one", "two", "three");
$section_hash{headings} = \@headings;
$section_hash{query} = "this is the query";
print_hash(\%section_hash);
exit;

sub print_hash {
    %sh = %{$_[0]};
    print "title = $sh{title}\n";
    print "comment = $sh{comment}\n";
    @headings_array = @{$sh{headings}};
    print "headings = ", @headings_array, "\n";
    print "query = $sh{query}\n";
    return;
}
