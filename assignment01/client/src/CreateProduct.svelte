<script>
    import {products, modal} from './store.js'

    const createProduct = (e) => {
        const newProduct = {};
        newProduct.name = e.target.name.value;
        newProduct.price = e.target.price.value;
        newProduct.quantity = e.target.quantity.value;
        console.log(newProduct);


        const url = "https://port-8000-mdkbzr-diliga8356426146.codeanyapp.com/api/v1/create-product"
        fetch(url, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(newProduct),

        })
        .then((res) => res.json())
        .then((data) => {
            console.log(data)
            products.set([{...data}, ...$products]);
            modal.update(p => 'none');
        })
        .catch((err) => {
            console.log(err)
        })
    }

</script>

<form on:submit|preventDefault={createProduct}>
    <label for="name">Product name:</label><br>
    <input required type="text" id="name" name="name" value=""><br>
    <br>
    <label for="price">Product price:</label><br>
    <input required type="number" id="price" name="price" value="" step="any" min=0/><br />
    <br>
    <label for="quantity">Product quantity:</label><br>
    <input required type="number" id="quantity" name="quantity" value="" step="1" min=0 /><br />
    <br>
    <button type="submit">Submit</button>
</form>

<style>
</style>
