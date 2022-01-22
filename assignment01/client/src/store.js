import { writable } from 'svelte/store';
const products = writable([]);
const modal = writable('none');
const isLoading = writable(false);
const productset = writable([]);
export {products, modal, isLoading, productset};