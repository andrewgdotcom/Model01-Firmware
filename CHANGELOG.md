Changelog
=========

2019-03-28
----------

* Cherrypicked upstream/master changes up to and including `d392c64`.
* Refactored `keymaps.h`
    * `layout-function-with-duplicates.h` has been removed.
    * All other layout files have been inlined in `keymaps.h`.
    * Migrated to the KEYMAPS macro, to track upstream.

2018-09-28
----------

* Rebased onto latest upstream/master
* The Great Renaming
    * Filenames have been reorganised to be shorter and more descriptive.
    * Layouts are now named for the class of keyboard layout they target.
    * QWERTY layer is now named PRIMARY to track upstream.
    * Scroll wheel behaviour settings have been inlined.
    * Layer names have been pushed down into layer files for clarity.
