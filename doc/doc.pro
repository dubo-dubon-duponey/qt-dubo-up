TEMPLATE = subdirs
OTHER_FILES +=  $$PWD/doxygen.tpl

# !win32
system(which doxygen){
    system(doxygen doxygen.tpl)
}else{
    warning(NO doxygen install - skipping documentation generation)
}
