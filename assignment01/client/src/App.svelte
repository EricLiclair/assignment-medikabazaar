<script>
    import TableRow from './TableRow.svelte';
    import AddProduct from './AddProduct.svelte';
    import SearchProducts from './SearchProducts.svelte';
    import {products, isLoading, productset} from './store.js'

    let url = 'https://port-8000-mdkbzr-diliga8356426146.codeanyapp.com/api/v1/products';
    const getProducts = () => {
        isLoading.set(true);
        fetch(url)
        .then((res) => res.json())
        .then((data) => {
            isLoading.set(false);
            products.set(data);
            productset.set(data);
        })
        .catch((err) => {
            console.log(err);
            isLoading.set(false);
        })
    }
    getProducts();
</script>

<SearchProducts />
<main>
    <table>
        <tr>
            <th>Id</th>
            <th>Name</th>
            <th>Price</th>
            <th>Quantity</th>
            <th>Tools</th>
        </tr>
    {#if $products.length > 0}
        {#each $products.slice(0, 300) as product (product.id)}
            <TableRow {product}/>
        {/each}
    {:else if $isLoading}
        <p>Loading...</p>
    {:else}
        <p>No products</p>
    {/if}
    </table>
    <br/>
</main>
<AddProduct />

<style>
    main {
        overflow-y: scroll;
        max-height: 450px;
    }
    table {
    font-family: Arial, Helvetica, sans-serif;
    border-collapse: collapse;
    width: 100%;
    }

    table tr th {
    padding: 1rem;
    text-align: left;
    background-color: #04AA6D;
    border: solid 1px #04AA6D;
    color: white;
    position: -webkit-sticky;
    position: sticky;
    top: 0px;
    z-index: 1;
    }
	main {
		text-align: center;
		margin: 0 auto;
	}
</style>