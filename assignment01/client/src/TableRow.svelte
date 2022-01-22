<script>
    export let product = {
        name: 'Product Name',
        price: 100.00,
        quantity: 100,
        id: 0
    }

    let updatedProduct = {
        name: null,
        price: null,
        quantity: null,
    }
    let editable = false;

    const toggle_editable = () => {
        editable = !editable;
    }

    const handleCancel = (e) => {
        e.stopPropagation();
        toggle_editable();
        product = {...product};
    }

    const updateProduct = (e, type) => {
        updatedProduct[type] = e.target.innerText;
    }

    const saveProductUpdate = () => {
        if (!(updatedProduct.name || updatedProduct.price || updatedProduct.quantity)) {
            product = {...product};
            editable = false;
            return;
        }
        let body = {
            name: updatedProduct.name ? updatedProduct.name : product.name,
            price: updatedProduct.price ? updatedProduct.price : product.price,
            quantity: updatedProduct.quantity ? updatedProduct.quantity : product.quantity,
        }
        let requestOptions = {
            method: 'PATCH',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(body)
        };
        fetch(`https://port-8000-mdkbzr-diliga8356426146.codeanyapp.com/api/v1/update-product/${product.id}`,requestOptions)
        .then((res) => res.json())
        .then((data) => {
            product = data;
            editable = !editable;
        })
        .catch((err) => {
            console.log(err);
            product = {...product};
        })
    }
</script>

<tr on:click={() => {editable = true;}}>
    <td >{product.id}</td>
    <td style="text-align: left;" on:input={(e) => updateProduct(e, 'name')} contenteditable={editable}>{product.name}</td>
    <td on:input={(e) => updateProduct(e, 'price')} contenteditable={editable}>{product.price}</td>
    <td on:input={(e) => updateProduct(e, 'quantity')} contenteditable={editable}>{product.quantity}</td>
    {#if editable}
        <td >
            <button on:click={saveProductUpdate}>save</button><button on:click={(e) => handleCancel(e)}>cancel</button>
        </td>
    {/if}
</tr>

<style>
    button {
        margin: 10px auto;
    }
    tr {
    border: 1px solid #ddd;
    }

    tr:nth-child(even){background-color: #f2f2f2;}

    tr:hover {background-color: #ddd;}
</style>