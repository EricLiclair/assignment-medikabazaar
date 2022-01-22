<script>
    import {products, productset} from './store.js'

    const filterFunction = (searchstring) => {
        let prd = $productset.filter(p => p.name.toLowerCase().indexOf(searchstring.toLowerCase()) >= 0)
        products.set(prd)
    }

    const searchDb = (productname) => {
        const url = productname ? `https://port-8000-mdkbzr-diliga8356426146.codeanyapp.com/api/v1/search/${productname}` : `https://port-8000-mdkbzr-diliga8356426146.codeanyapp.com/api/v1/products` ;
        fetch(url)
        .then((res) => res.json())
        .then((data) => {
            productset.set(data)
            products.set(data)
        })
        .catch(err => console.log(err))
    }


</script>

<div style="margin: 1rem 0;">
    <!-- on:input={(e) => filterFunction(e.target.value)} -->
    <input 
        on:change={(e) => {searchDb(e.target.value)}} 
        placeholder="Type product name to filter: press search to Search the db" 
    >
    <button on:click={() => searchDb('')}>
        fetch all
    </button>
    
</div>