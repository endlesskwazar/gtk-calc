#include <gtk/gtk.h>
#include "store.h"
#include "eventHandlers.h"

int main (int argc, char **argv)
{
    Store *store = new Store();
    GtkWidget* window;
    GtkWidget* rootContainer;
    GtkWidget* plusButton;
    GtkWidget* minusButton;
    GtkWidget* sevenButton;
    GtkWidget* eightButton;
    GtkWidget* nineButton;
    GtkWidget* fourButton;
    GtkWidget* fiveButton;
    GtkWidget* sixButton;
    GtkWidget* mulButton;
    GtkWidget* oneButton;
    GtkWidget* twoButton;
    GtkWidget* threeButton;
    GtkWidget* divisionButton;
    GtkWidget* zeroButton;
    GtkWidget* equalButton;

    gtk_init(&argc, &argv);

    //inti the window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello world");
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //init
    rootContainer = gtk_grid_new();
    store->calcDisplayEntry = gtk_entry_new();
    //disable entry
    g_object_set(store->calcDisplayEntry, "editable", FALSE);
    g_object_set(store->calcDisplayEntry, "can_focus", FALSE);
    gtk_widget_set_hexpand(store->calcDisplayEntry, true);
    plusButton = gtk_button_new_with_label("+");
    gtk_widget_set_vexpand(GTK_WIDGET(plusButton), TRUE);
    minusButton = gtk_button_new_with_label("-");
    gtk_widget_set_vexpand(GTK_WIDGET(minusButton), TRUE);
    mulButton = gtk_button_new_with_label("*");
    gtk_widget_set_vexpand(GTK_WIDGET(mulButton), TRUE);
    sevenButton = gtk_button_new_with_label("7");
    eightButton = gtk_button_new_with_label("8");
    nineButton = gtk_button_new_with_label("9");
    fourButton = gtk_button_new_with_label("4");
    fiveButton = gtk_button_new_with_label("5");
    sixButton = gtk_button_new_with_label("6");
    oneButton = gtk_button_new_with_label("1");
    twoButton = gtk_button_new_with_label("2");
    threeButton = gtk_button_new_with_label("3");
    divisionButton = gtk_button_new_with_label("/");
    gtk_widget_set_vexpand(GTK_WIDGET(divisionButton), TRUE);
    zeroButton = gtk_button_new_with_label("0");
    equalButton = gtk_button_new_with_label("=");

    //pack the widgets
    gtk_grid_attach(GTK_GRID(rootContainer),store->calcDisplayEntry,0,0,4,1);
    //first row
    gtk_grid_attach(GTK_GRID(rootContainer),plusButton,0,1,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),sevenButton,1,1,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),eightButton,2,1,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),nineButton,3,1,1,1);
    //second row
    gtk_grid_attach(GTK_GRID(rootContainer),minusButton,0,2,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),fourButton,1,2,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),fiveButton,2,2,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer),sixButton,3,2,1,1);
    //third row
    gtk_grid_attach(GTK_GRID(rootContainer), mulButton, 0,3,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer), oneButton, 1,3,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer), twoButton, 2,3,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer), threeButton, 3,3,1,1);
    //fourth row
    gtk_grid_attach(GTK_GRID(rootContainer), divisionButton, 0,4,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer), zeroButton, 1,4,1,1);
    gtk_grid_attach(GTK_GRID(rootContainer), equalButton, 2,4,2,1);

    //connects the signals
    g_signal_connect(sevenButton, "clicked", G_CALLBACK(on_seven_button_clicked), store);
    g_signal_connect(plusButton, "clicked", G_CALLBACK(on_plus_button_clicked), store);
    g_signal_connect(equalButton, "clicked", G_CALLBACK(on_equal_button_clicked), store);

    //show the window
    gtk_container_add(GTK_CONTAINER(window), rootContainer);
    gtk_widget_show_all(window);
    gtk_main();
}
